#include "tdictionnary.h"

#include "tbytes.h"
#include "tinteger.h"
#include "tstring.h"
#include "tlist.h"

TDictionary::TDictionary(TBytes* bytes)
{
    this->type = DICTIONNARY;
    this->read(bytes);
}

void TDictionary::read(TBytes *bytes)
{
    unsigned char c = bytes->nextByte();

    //Checks that the leading 'l' is present
    if(c != 'd')
        return;

    //While we don't meet the trailing 'e'
    while(c != 'e')
    {
        TString *key = new TString(bytes);
        TData *data = 0;
        switch(bytes->getNextType())
        {
        case INTEGER:
            data = new TInteger(bytes);
            break;
        case STRING:
            data = new TString(bytes);
            break;
        case LIST:
            data = new TList(bytes);
            break;
        case DICTIONNARY:
            data = new TDictionary(bytes);
            break;
        }

        if(data != 0)
        {
            this->values.insert(std::make_pair(key->getValue(),data));
            c = bytes->currentByte();
        }
        else
        {
            c = bytes->nextByte();
        }
    }
}

std::string TDictionary::toString()
{
    std::map<std::string, TData*>::iterator it;

    std::ostringstream oss;
    oss << "d";
    for (it = this->values.begin(); it != this->values.end(); it++)
    {
        oss << it->first.size() << ":" << it->first << it->second->toString();
    }
    oss << "e";
    return oss.str();
}

std::string TDictionary::toJson()
{
    std::map<std::string, TData*>::iterator it;

    std::ostringstream oss;
    oss << "[";

    for (it = this->values.begin(); it != this->values.end(); it++)
    {
        oss << "\"" << it->first << "\":" << it->second->toJson() << ",";
    }

    std::string json = oss.str();
    json = json.substr(0,json.length()-1);
    json += "]";

    return json;
}

bool TDictionary::hasKey(std::string key)
{
    return this->values.count(key);
}

TData* TDictionary::get(std::string key)
{
    if(this->values.count(key))
        return this->values[key];
    else
        return 0;
}

TString* TDictionary::getString(std::string key)
{
    return (TString*)get(key);
}

TList* TDictionary::getList(std::string key)
{
    return (TList*)get(key);
}

TInteger* TDictionary::getInt(std::string key)
{
    return (TInteger*)get(key);
}

TDictionary* TDictionary::getDictionary(std::string key)
{
    return (TDictionary*)get(key);
}

int TDictionary::getIntVal(std::string key, int def)
{
    return this->hasKey(key) ? this->getInt(key)->getValue() : def;
}

std::string TDictionary::getStringVal(std::string key, std::string def)
{
    return this->hasKey(key) ? this->getString(key)->getValue() : def;
}
