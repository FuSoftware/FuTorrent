#include "tlist.h"

#include "tbytes.h"
#include "tinteger.h"
#include "tstring.h"
#include "tdictionnary.h"

TList::TList(TBytes *bytes)
{
    this->type = LIST;
    this->read(bytes);
}

void TList::read(TBytes *bytes)
{
    unsigned char c = bytes->nextByte();

    //Checks that the leading 'l' is present
    if(c != 'l')
        return;

    //While we don't meet the trailing 'e'
    while(c != 'e')
    {
        TData *t = 0;
        switch(bytes->getNextType())
        {
        case INTEGER:
            t = new TInteger(bytes);
            break;
        case STRING:
            t = new TString(bytes);
            break;
        case LIST:
            t = new TList(bytes);
            break;
        case DICTIONNARY:
            t = new TDictionary(bytes);
            break;
        }

        if(t != 0)
        {
            this->values.push_back(t);
            c = bytes->nextByte();
        }
        else
        {
            c = bytes->nextByte();
        }
    }

    bytes->nextByte();
}

std::vector<TData*> TList::getValues()
{
    return this->values;
}

std::string TList::toString()
{
    std::ostringstream oss;
    oss << "l";

    for(int i=0;i<values.size();i++)
    {
        oss << values[i]->toString();
    }

    oss << "e";

    return oss.str();
}

std::string TList::toJson()
{
    std::ostringstream oss;

    oss << "[";

    for(int i=0;i<values.size();i++)
    {
        oss << values[i]->toJson() << ",";
    }

    std::string json = oss.str();
    json = json.substr(0,json.length()-1);
    json += "]";

    return json;
}

TData* TList::get(int index)
{
    return this->values.at(index);
}

TString* TList::getString(int index)
{
    return (TString*)get(index);
}

TList* TList::getList(int index)
{
    return (TList*)get(index);
}

TInteger* TList::getInt(int index)
{
    return (TInteger*)get(index);
}

TDictionary* TList::getDictionary(int index)
{
    return (TDictionary*)get(index);
}

int TList::getIntVal(int index)
{
    return this->getInt(index)->getValue();
}

std::string TList::getStringVal(int index)
{
    return this->getString(index)->getValue();
}


int TList::getCount()
{
    return this->values.size();
}
