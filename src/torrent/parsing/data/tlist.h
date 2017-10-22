#ifndef TLIST_H
#define TLIST_H

#include "tdata.h"
#include <vector>
#include <sstream>

class TDictionary;
class TString;
class TInteger;

class TList : public TData
{
public:
    TList(TBytes *bytes);
    void read(TBytes *bytes);
    std::string toString();
    std::string toJson();
    int getCount();

    std::vector<TData*> getValues();
    TData* get(int index);
    TString* getString(int index);
    TList* getList(int index);
    TInteger* getInt(int index);
    TDictionary* getDictionary(int index);
    int getIntVal(int index);
    std::string getStringVal(int index);

private:
    std::vector<TData*> values;
};

#endif // TLIST_H
