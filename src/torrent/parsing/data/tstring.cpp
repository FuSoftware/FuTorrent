#include "tstring.h"
#include "tbytes.h"

TString::TString(TBytes *bytes)
{
    this->type = STRING;
    this->read(bytes);
}

void TString::read(TBytes *bytes)
{
    this->bytes.clear();

    //Reads bytes until it sees a ":"
    unsigned char c_char= bytes->nextByte();

    std::vector<char> lengthBytes;

    while(c_char != ':')
    {
        lengthBytes.push_back(c_char);
        c_char = bytes->nextByte();
    }

    //Adds all the read digits from LSB to MSB, converting from ASCII to decimal
    this->str_length = 0;
    int factor = 1;
    for(int i=lengthBytes.size()-1;i>=0;i--)
    {
        this->str_length += (lengthBytes[i] - 0x30) * factor;
        factor *= 10;
    }

    //Reads the x next bytes to get the string value
    std::vector<char> str_bytes = bytes->nextBytes(this->str_length);
    this->str = std::string(str_bytes.begin(), str_bytes.end());
}

std::string TString::getValue()
{
    return this->str;
}

std::string TString::toString()
{
    return this->str;
}

std::string TString::toJson()
{
    return "\"" + this->str + "\"";
}
