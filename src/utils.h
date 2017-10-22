#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <fstream>

class Utils
{
public:
    Utils();

    static std::vector<char> readAllBytes(std::string file);
};

#endif // UTILS_H
