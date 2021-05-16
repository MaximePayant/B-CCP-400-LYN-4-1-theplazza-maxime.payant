/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** time.cpp
*/

#include <ctime>
#include <sstream>
#include <iostream>
#include <iomanip>

#include "shell.hpp"

std::string plz::getTime()
{
    std::time_t now = std::time(NULL);
    std::tm *stime = localtime(&now);
    std::stringstream sstring;

    sstring << "[" << std::setfill('0') << std::setw(2) << stime->tm_hour
            << ":" << std::setfill('0') << std::setw(2) << stime->tm_min
            << ":" << std::setfill('0') << std::setw(2) << stime->tm_sec
            << "] - ";
    return (sstring.str());
}

void plz::writeLog(const std::string& message)
{
    plz::Shell::fileStream << plz::getTime() << message << std::endl;
}