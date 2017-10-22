#include "torrentparser.h"

#include "data/tdictionnary.h"
#include "data/tbytes.h"


TorrentParser::TorrentParser(std::string file)
{

}

TorrentParser::TorrentParser(std::vector<char> data)
{

}

void TorrentParser::parse(std::vector<char> data)
{
    TBytes *b = new TBytes(data);
    TDictionary *d = new TDictionary(b);
}
