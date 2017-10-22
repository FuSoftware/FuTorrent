#ifndef TSTRING_H
#define TSTRING_H

#include <string>
#include "tdata.h"

class TString : public TData
{
public:
    TString(TBytes *bytes);
    void read(TBytes *bytes);
    std::string toString();
    std::string toJson();

    std::string getValue();

private:
    std::string str = "";
    int str_length = 0;
};

#endif // TSTRING_H
