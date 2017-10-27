#include "tests.h"
#include "torrent/torrentfile.h"
#include "utils/sha1.h"

#include <QFileDialog>

void testString()
{
    std::string s0 = testString("4:spam");
    std::string s1 = testString("8:announce");
    std::string s2 = testString("33:http://explodie.org:6969/announce");

    std::cout << s0 << std::string(" | ") << s1 << std::string(" | ") << s2 << std::endl;
}

std::string testString(std::string bytes)
{
    std::vector<char> v(bytes.begin(), bytes.end());
    TBytes *data = new TBytes(v);
    TString *str = new TString(data);

    return str->getValue();
}

void testInteger()
{
    int s0 = testInteger("i25e");
    int s1 = testInteger("i123456e");
    int s2 = testInteger("i-658e");

    std::cout << "i25e" << " -> " << s0
              << std::endl
              << "i123456e" << " -> " << s1
              << std::endl
              << "i-658e" << " -> " << s2
              << std::endl;
}

int testInteger(std::string bytes)
{
    std::vector<char> v(bytes.begin(), bytes.end());
    TBytes *data = new TBytes(v);
    TInteger *i = new TInteger(data);

    return i->getValue();
}

void testList()
{
    std::cout << testList("l4:spam4:eggse") << std::endl
              << testList("l4:spami389e4:eggse") << std::endl
              << testList("l4:spami389el5:spame6:spameze4:eggse") << std::endl;
}

std::string testList(std::string bytes)
{
    std::vector<char> v(bytes.begin(), bytes.end());
    TBytes *data = new TBytes(v);
    TList *list = new TList(data);
    return list->toJson();
}

void testDictionary()
{
    std::cout << testDictionary("d3:cow3:moo4:spam4:eggse") << std::endl
              << testDictionary("d4:spaml1:a1:bee") << std::endl
              << testDictionary("d9:publisher3:bob17:publisher-webpage15:www.example.com18:publisher.location4:homee") << std::endl;
}

std::string testDictionary(std::string bytes)
{
    std::vector<char> v(bytes.begin(), bytes.end());
    TBytes *data = new TBytes(v);
    TDictionary *d = new TDictionary(data);
    return d->toString();
}

void testTorrentDic()
{
    QString path = QFileDialog::getOpenFileName(0,"Torrent File","","Torrent files (*.torrent);;");
    testTorrentDic(path.toStdString());
}

void testTorrentDic(std::string file)
{
    TorrentFile *t = new TorrentFile();
    t->loadFile(file);
    std::cout << "Announce : " << t->getAnnounce() << std::endl;

    std::vector<ReceivedFileInfo> files = t->getFiles();

    for(int i=0;i<files.size();i++)
    {
        std::cout << "File " << i << " : " << files[i].path << " (" << files[i].md5sum << ")" << std::endl;
    }
}

void testDictionaryHash(std::string dic)
{
    TBytes *data = new TBytes(dic);
    TDictionary *d = new TDictionary(data);
    std::cout << d->toString() << " => " << sha1(d->toString()) << std::endl;
}
