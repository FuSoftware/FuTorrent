#include "torrentfile.h"
#include "utils.h"
#include "parsing/data/tbytes.h"
#include "utils/sha1.h"

TorrentFile::TorrentFile()
{

}

void TorrentFile::loadFile(std::string path)
{
    TBytes *b = new TBytes(Utils::readAllBytes(path));
    loadDictionnary(new TDictionary(b));
}

void TorrentFile::loadDictionnary(TDictionary *dic)
{
    //General Info
    this->announce = dic->getStringVal("announce");
    this->creation_date = dic->getIntVal("creation date");
    this->comment = dic->getStringVal("comment");
    this->created_by = dic->getStringVal("created_by");
    this->encoding = dic->getStringVal("encoding");

    //Info Header
    TDictionary *info = dic->getDictionary("info");

    this->info_hash = sha1(info->toString());

    if(info->hasKey("files"))
    {
        //Multi File
        TList *files = info->getList("files");

        for(int i=0; i<files->getCount(); i++)
        {
            TDictionary *file = files->getDictionary(i);
            ReceivedFileInfo fileInfo;

            std::string pathStr = "";
            TList *pathList = file->getList("path");

            for(int j=0; j<pathList->getCount(); j++)
            {
                pathStr += pathList->getStringVal(i) + "/";
            }

            fileInfo.path = pathStr;
            fileInfo.length = file->getIntVal("length");
            fileInfo.md5sum = file->getStringVal("md5sum");

            this->files.push_back(fileInfo);
        }
    }
    else
    {
        //Single File
        ReceivedFileInfo fileInfo;
        fileInfo.path = info->getStringVal("name");
        fileInfo.length = info->getIntVal("length");
        fileInfo.md5sum = info->getStringVal("md5sum");
        this->files.push_back(fileInfo);
    }
}

std::vector<ReceivedFileInfo> TorrentFile::getFiles()
{
    return this->files;
}

std::string TorrentFile::getAnnounce()
{
    return this->announce;
}

int TorrentFile::getCreationDate()
{
    return this->creation_date;
}

std::string TorrentFile::getComment()
{
    return this->comment;
}

std::string TorrentFile::getCreatedBy()
{
    return this->created_by;
}

std::string TorrentFile::getEncoding()
{
    return this->encoding;
}

std::string TorrentFile::getInfoHash()
{
    return this->info_hash;
}

std::vector<std::string> TorrentFile::getTrackerUrls()
{

}
