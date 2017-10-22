#include "utils.h"

Utils::Utils()
{

}

std::vector<char> Utils::readAllBytes(std::string file)
{
    std::ifstream ifs(file, std::ios::binary|std::ios::ate);
    std::ifstream::pos_type pos = ifs.tellg();

    std::vector<char> result(pos);

    ifs.seekg(0, std::ios::beg);
    ifs.read(&result[0], pos);

    return result;
}
