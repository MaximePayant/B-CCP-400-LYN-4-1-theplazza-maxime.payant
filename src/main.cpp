/*
** EPITECH PROJECT, 2021
** main.cpp
** File description:
** main.cpp
*/

#include <iostream>
#include <unistd.h>
#include "shell.hpp"
#include "communication/message.hpp"
#include "shell.hpp"

#include "Kitchen.hpp"
#include "chrono/Chrono.hpp"

void helpCase()
{
    std::cout   << "USAGE" << std::endl
                << "\t./plazza [a] [b] [c]" << std::endl << std::endl
                << "DESCRIPTION" << std::endl
                << "\t[a] is a cooking time multiplier. It is able to accept value between 0 to 1 to obtain a divisor of the pizza cooking time ;" << std::endl
                << "\t[b] is the number of cooker per kitchen ;" << std::endl
                << "\t[c] is the delivery time for ingredient. Each [c] millisecond, the stock of all ingredient would be refill by 1." << std::endl;
}

int main(int ac, char **av)
{
    if (ac < 4) {
        helpCase();
        if (ac == 2
        && (std::string(av[1]) == "-h" || std::string(av[1]) == "--help"))
            return (0);
        return (84);
    }
    try {
        plz::Shell shell(std::stof(av[1]), std::stoi(av[2]), std::stoi(av[3]));
        shell.exec();
    }
    catch (std::exception const &error) {
        std::cerr << error.what() << std::endl;
    }
    return (0);
}