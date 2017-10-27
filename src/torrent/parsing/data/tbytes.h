#ifndef TBYTES_H
#define TBYTES_H

#include <vector>
#include <string>

class TData;

class TBytes
{
public:
    TBytes(std::vector<char> bytes);
    TBytes(std::string text);

    char nextByte();
    char currentByte();
    std::vector<char> nextBytes(int length);

    std::vector<char> getBytes(int start, int length);
    std::string getText(int start, int length);

    int getCurrentPosition();
    bool isEOF();
    void setPosition(int position);

    void setBytes(std::vector<char> bytes);

    int getNextType();

private:
    std::vector<char> bytes;
    std::string bytes_str;
    unsigned int position = 0;

};

#endif // TBYTES_H
