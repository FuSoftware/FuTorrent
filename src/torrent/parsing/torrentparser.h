#ifndef TORRENTPARSER_H
#define TORRENTPARSER_H

#include "../torrentfile.h"
#include <iostream>
#include <vector>

class TorrentParser
{
public:
    TorrentParser(std::string file);
    TorrentParser(std::vector<char> data);

private:
    void parse(std::vector<char> data);
};

#endif // TORRENTPARSER_H
