#include "tstring.h"
#include "tbytes.h"
#include <sstream>

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
        if(c_char >= '0' && c_char <= '9')
        {
            lengthBytes.push_back(c_char);
            c_char = bytes->nextByte();
        }
        else
        {
            std::ostringstream oss;
            oss << "Trying to read TString length but found a NaN character " << c_char << " at position " << bytes->getCurrentPosition() << std::endl;
            oss << "Surrounding bytes => " << bytes->getText(bytes->getCurrentPosition()-10, 20);
            throw std::runtime_error(oss.str());
        }

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
    std::ostringstream oss;
    oss << this->str.length() << ":" << this->str;
    return oss.str();
}

std::string TString::toJson()
{
    return "\"" + this->str + "\"";
}
