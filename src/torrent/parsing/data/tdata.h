#ifndef TDATA_H
#define TDATA_H

#include <vector>
#include <string>

class TBytes;

class TData
{
public:
    TData();

    virtual void read(TBytes *bytes) = 0;
    virtual std::string toString() = 0;
    virtual std::string toJson() = 0;

    std::vector<char> getBytes();

    static int checkType(char c);

    enum BENCODED_TYPE
    {
        STRING = 0,
        INTEGER,
        LIST,
        DICTIONNARY,
        VALUE
    };

protected:
    BENCODED_TYPE type = BENCODED_TYPE::VALUE;
    int position = 0;
    int length = 0;
    std::vector<char> bytes;

};

#endif // TDATA_H
