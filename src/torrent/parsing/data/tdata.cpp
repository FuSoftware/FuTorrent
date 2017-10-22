#include "tdata.h"

TData::TData()
{

}

std::vector<char> TData::getBytes()
{
    return this->bytes;
}

int TData::checkType(char c)
{
    if(c == 'i')
    {
        return INTEGER;
    }
    else if(c == 'd')
    {
        return DICTIONNARY;
    }
    else if(c == 'l')
    {
        return LIST;
    }
    else
    {
        return STRING;
    }
}
