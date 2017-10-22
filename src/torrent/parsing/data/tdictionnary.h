#ifndef TDICTIONNARY_H
#define TDICTIONNARY_H

#include "tdata.h"

#include <map>
#include <utility>
#include <sstream>

class TList;
class TString;
class TInteger;

class TDictionary : public TData
{
public:
    TDictionary(TBytes* bytes);
    void read(TBytes *bytes);
    std::string toString();
    std::string toJson();

    bool hasKey(std::string key);
    TData* get(std::string key);
    TString* getString(std::string key);
    TList* getList(std::string key);
    TInteger* getInt(std::string key);
    TDictionary* getDictionary(std::string key);

    int getIntVal(std::string key, int def = 0);
    std::string getStringVal(std::string key, std::string def = "");

private:
    std::map<std::string, TData*> values;

};

#endif // TDICTIONNARY_H
