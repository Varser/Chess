#include "logger.h"

int stoi(std::string myStream)
{
    std::istringstream buffer(myStream);
    int value;
    buffer >> value;
    return value;
}
