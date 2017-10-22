#ifndef TINTEGER_H
#define TINTEGER_H

#include "tdata.h"

#include <sstream>

class TInteger : public TData
{
public:
    TInteger(TBytes *bytes);
    void read(TBytes *bytes);
    std::string toString();
    std::string toJson();

    int getValue();

private:
    int value;
};

#endif // TINTEGER_H
