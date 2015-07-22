#include "logger.h"
#include <string>
#include <fstream>

const std::string g_k_logFileName = "last_saved.log";

size_t Logger::s_m_position = 0;
std::vector<std::pair<Coordinates, Coordinates> > Logger::s_m_steps;

namespace internals
{
    unsigned short CharToUnsignedShort(const char ch)
    {
        unsigned short result = ch;
        result -= '0';
        return result;
    }
}

std::pair<Coordinates, Coordinates> Logger::Prev()
{
    if (!s_m_position)
        return std::pair<Coordinates, Coordinates>();
        --s_m_position;
    return s_m_steps[s_m_position];
}

std::pair<Coordinates, Coordinates> Logger::Next()
{
    if (s_m_position < s_m_steps.size())
        ++s_m_position;
    return s_m_steps[s_m_position - 1];
}

void Logger::Set(std::pair<Coordinates, Coordinates> step)
{
    ++s_m_position;
    while (s_m_steps.size() >= s_m_position)
    {
        s_m_steps.pop_back();
    }
    s_m_steps.push_back(step);
}

void Logger::SaveLog()
{
    if (!s_m_position)
        return;
    std::ofstream ofs(g_k_logFileName.c_str(), std::ios_base::out);
    if (!ofs.is_open())
        return;
    for (std::vector<std::pair<Coordinates, Coordinates> >::iterator iter = s_m_steps.begin(); iter != s_m_steps.end(); ++iter)
    {
        unsigned short value = iter->first.x()*1000 + iter->first.y()*100 + iter->second.x()*10 + iter->second.y();
        ofs << value << std::endl;
    }
    ofs.close();
}

void Logger::LoadLog()
{
    s_m_steps.clear();
    s_m_position = 0;
    std::ifstream ifs(g_k_logFileName.c_str(), std::ios_base::in);
    if (!ifs.is_open())
        return;
    while(ifs && !ifs.eof())
    {
        std::string value;
        ifs >> value;
        if (value.empty())
            break;
        s_m_steps.push_back(std::pair<Coordinates, Coordinates>
                            (Coordinates(internals::CharToUnsignedShort(value[0]), internals::CharToUnsignedShort(value[1])),
                            Coordinates(internals::CharToUnsignedShort(value[2]), internals::CharToUnsignedShort(value[3]))));
    }
    ifs.close();
    s_m_position = s_m_steps.size();
}

bool Logger::isEmpty()
{
    return !s_m_position;
}

std::vector<std::pair<Coordinates, Coordinates> > Logger::GetLog()
{
    while (s_m_steps.size() > s_m_position)
    {
        s_m_steps.pop_back();
    }
    return s_m_steps;
}

void Logger::Clear()
{
    s_m_steps.clear();
    s_m_position = 0;
}

size_t Logger::GetMoveNumber()
{
    return s_m_position;
}

