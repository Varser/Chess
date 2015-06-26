#ifndef LOGGER_H
#define LOGGER_H

#include <map>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

#include"piece.h"

const std::string g_k_logFile = "last_saved.log";

int stoi(std::string myStream);

class Logger
{
private:
    std::map<size_t, std::pair<Coordinates, Coordinates> > m_map;
    size_t m_currentPosition;

public:
    void AddToLog(Coordinates coordinates, Coordinates prev)
    {
        if (m_currentPosition != m_map.size() - 1)
            m_map.erase(m_map.find(m_currentPosition), m_map.end());
        m_map[m_currentPosition] = make_pair(coordinates, prev);
        ++m_currentPosition;
    }

    bool SaveLog()
    {
        std::ofstream ofs(g_k_logFile.c_str(), std::ios::out);
        if (!ofs || !ofs.is_open())
            return false;
        for (std::map<size_t, Coordinates>::iterator iterator = m_map.begin(); iterator != m_map.end(); ++iterator)
        {
            ofs << iterator->second->first.x() << "-" << iterator->second->first.y() << "-" << iterator->second->second.x() << "-" << iterator->second->second.y() << std::endl;
        }
        return true;
    }

    inline bool LoadLog()
    {
        m_map.clear();
        std::ifstream ifs(g_k_logFile.c_str(), std::ios::in);
        if (!ifs || !ifs.is_open())
            return false;
        std::string line;
        while(std::getline(ifs, line))
        {
            m_map.insert(std::pair<size_t, Coordinates>(++m_currentPosition, Coordinates(stoi(line.substr(0, line.find("-"))), stoi(line.substr(line.find("-") + 1)), false)));
        }
        return true;
    }

    inline Coordinates GetMove() {return m_map[m_currentPosition];}

    bool GoToPrevMove()
    {
        if (m_currentPosition > 0)
        {
            --m_currentPosition;
            return true;
        }
        return false;
    }

    bool GoToNextMove()
    {
        if (m_currentPosition < m_map.size() - 1)
        {
            ++m_currentPosition;
            return true;
        }
        return false;
    }

    inline void clearLog()
    {
        m_map.clear();
        m_currentPosition = 0;
    }

private:
    Logger() : m_currentPosition(0) {}
    Logger(const Logger&);
    void * operator=(const Logger&);
public:
    static Logger& GetLogger()
    {
        static Logger _logger;
        return _logger;
    }
};

#endif // LOGGER_H
