#ifndef QTRACKER_H
#define QTRACKER_H

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>

#include "torrent/tracker/tracker.h"

class QTracker : public Tracker
{
public:
    QTracker(QString url, TorrentFile *parent);

    void request();
    void request(HttpTrackerRequest req);
private:

    QString url;
};

#endif // QTRACKER_H
