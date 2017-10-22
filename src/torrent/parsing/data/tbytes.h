#ifndef TBYTES_H
#define TBYTES_H

#include <vector>

class TData;

class TBytes
{
public:
    TBytes(std::vector<char> bytes);

    char nextByte();
    char currentByte();
    std::vector<char> nextBytes(int length);

    int getCurrentPosition();
    bool isEOF();
    void setPosition(int position);

    void setBytes(std::vector<char> bytes);

    int getNextType();

private:
    std::vector<char> bytes;
    unsigned int position = 0;

};

#endif // TBYTES_H
