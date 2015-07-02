#ifndef LOGGER_H
#define LOGGER_H
#include "piece.h"
#include <vector>


class Logger
{
public:
    static std::pair<Coordinates, Coordinates> Prev();
    static std::pair<Coordinates, Coordinates> Next();
    static void Set(std::pair<Coordinates, Coordinates> step);
    static void SaveLog();
    static void LoadLog();
    static bool isEmpty();
    static void Clear();
    static size_t GetMoveNumber();
    static std::vector<std::pair<Coordinates, Coordinates> > GetLog();
private:
    static std::vector<std::pair<Coordinates, Coordinates> > s_m_steps;
    static size_t s_m_position;
};

#endif // LOGGER_H
