#include "tinteger.h"
#include "tbytes.h"

TInteger::TInteger(TBytes *bytes)
{
    this->type = INTEGER;
    this->read(bytes);
}

void TInteger::read(TBytes *bytes)
{
    unsigned char c = bytes->nextByte();
    bool negative = false;

    //Checks that the leading 'i' is present
    if(c == 'i')
        c = bytes->nextByte();
    else
        return;

    //Checks the negative sign before handling numbers
    if(c == '-')
    {
        negative = true;
        c = bytes->nextByte();
    }

    this->bytes.clear();

    while(c != 'e')
    {
        this->bytes.push_back(c);
        c = bytes->nextByte();
    }

    this->value = 0;
    int factor = 1;
    for(int i=this->bytes.size()-1;i>=0;i--)
    {
        this->value += (this->bytes[i] - 0x30) * factor;
        factor *= 10;
    }

    if(negative)
        this->value *= -1;
}

int TInteger::getValue()
{
    return this->value;
}

std::string TInteger::toString()
{
    std::ostringstream oss;
    oss << "i" << this->value << "e";
    return oss.str();
}

std::string TInteger::toJson()
{
    return this->toString();
}
