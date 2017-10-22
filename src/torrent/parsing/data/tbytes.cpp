#include "tbytes.h"

#include "tdata.h"

TBytes::TBytes(std::vector<char> bytes)
{
    setBytes(bytes);
}

char TBytes::nextByte()
{
    if(this->position+1 < this->bytes.size())
        return this->bytes[this->position++];
    else
        return '\­0';
}

char TBytes::currentByte()
{
    return this->bytes[this->position];
}

std::vector<char> TBytes::nextBytes(int length)
{
    std::vector<char> data(this->bytes.begin() + this->position, this->bytes.begin() + this->position + length);
    this->position += length;
    return data;
}

int TBytes::getCurrentPosition()
{
    return this->position;
}

bool TBytes::isEOF()
{
    return this->position >= this->bytes.size();
}

void TBytes::setPosition(int position)
{
    this->position = position;
}

void TBytes::setBytes(std::vector<char> bytes)
{
    this->bytes = bytes;
}

int TBytes::getNextType()
{
    return TData::checkType(currentByte());
}
