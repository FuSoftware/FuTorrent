#include "tracker.h"
#include "torrent/parsing/data/tdictionnary.h"
#include "torrent/parsing/data/tlist.h"
#include "torrent/parsing/data/tbytes.h"
#include "utils/sha1.h"

#include <sstream>

Tracker::Tracker(std::string url, TorrentFile *parent)
{
    this->url = url;
    this->parent = parent;
}

std::string Tracker::getDummyParameters()
{
    HttpTrackerRequest request;

    request.info_hash = this->parent->getInfoHash();
    request.peer_id = sha1("test");
    request.port = 6881;
    request.uploaded = 0;
    request.downloaded = 0;
    request.left = 0;
    request.compact = 0;
    request.no_peer_id = 0;
    request.event = "started";

    return getParameters(request);
}

std::string Tracker::getParameters()
{
    return "";
}

std::string Tracker::getParameters(HttpTrackerRequest request)
{
    std::ostringstream oss;

    oss << "?";
    oss << "info_hash=" << request.info_hash << "&";
    oss << "peer_id=" << request.peer_id << "&";
    oss << "port=" << request.port << "&";
    oss << "uploaded=" << request.uploaded << "&";
    oss << "downloaded=" << request.downloaded << "&";
    oss << "left=" << request.left << "&";
    oss << "compact=" << request.compact << "&";
    oss << "no_peer_id=" << request.no_peer_id << "&";
    oss << "event=" << request.event << "&";
    if( request.numwant != 0) oss << "numwant=" << request.numwant << "&";
    if( !request.ip.empty()) oss << "ip=" << request.ip << "&";
    if( !request.key.empty()) oss << "key=" << request.key << "&";
    if( !request.trackerid.empty()) oss << "trackerid=" << request.trackerid;

    std::string params = oss.str();
    if(params[params.length()-1] == '&') params.pop_back();
    return params;
}

HttpTrackerResponse Tracker::parseResponse(std::string data)
{
    TBytes *b = new TBytes(data);
    TDictionary *d = new TDictionary(b);

    HttpTrackerResponse response;
    response.complete = d->getIntVal("complete");
    response.incomplete = d->getIntVal("incomplete");
    response.failure_reason = d->getStringVal("failure reason");
    response.warning_message = d->getStringVal("warning message");
    response.min_interval = d->getIntVal("min interval");
    response.tracker_id = d->getStringVal("tracker id");

    std::string peers = d->getStringVal("peers");

    delete b;
    b = new TBytes(peers);
    TList *l = new TList(b);

    for(int i=0;i<l->getCount();i++)
    {
        TDictionary *pDict = l->getDictionary(i);
        Peer p;
        p.id = pDict->getStringVal("id");
        p.ip = pDict->getStringVal("ip");
        p.port = pDict->getIntVal("port");
    }
}
