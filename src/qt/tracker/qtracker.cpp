#include "qtracker.h"

QTracker::QTracker(QString url, TorrentFile *parent) : Tracker(url.toStdString(), parent)
{
    this->url = url;
}

void QTracker::request()
{
    QString url = this->url + QString::fromStdString(getDummyParameters());
}

void QTracker::request(HttpTrackerRequest req)
{

}
