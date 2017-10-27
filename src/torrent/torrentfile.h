#ifndef TORRENTFILE_H
#define TORRENTFILE_H

#include <map>
#include <utility>
#include <string>
#include <vector>
#include <fstream>

#include "parsing/data/tdatatypes.h"

struct ReceivedFileInfo
{
    int length;
    std::string md5sum;
    std::string path;
};


class TorrentFile
{
public:
    TorrentFile();

    void loadDictionnary(TDictionary *dic);
    void loadFile(std::string path);

    std::string getAnnounce();
    int getCreationDate();
    std::string getComment();
    std::string getCreatedBy();
    std::string getEncoding();
    std::vector<ReceivedFileInfo> getFiles();
    std::vector<std::string> getTrackerUrls();

    std::string getInfoHash(); //SHA1 hash

private:
    //Info Header
    int piece_length;
    std::vector<std::string> pieces;
    int private_tracker;

    //File Info
    bool single_file = true;

    std::vector<ReceivedFileInfo> files;

    //Other data
    std::string announce;
    std::string announce_list;
    int creation_date;
    std::string comment;
    std::string created_by;
    std::string encoding;

    std::string info_hash;

};

#endif // TORRENTFILE_H
