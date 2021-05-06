/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** plazza
*/

#ifndef PLAZZA_HPP_
#define PLAZZA_HPP_
#include <iostream>
#include <string>
#include <regex>
#include <iterator>
#include <queue>
#include <unistd.h>

namespace plz {
    enum PizzaType {
        Margarita = 2,
        Regina = 1,
        Americana = 4,
        Fantasia = 8
    };
    enum PizzaSize {
        S = 1,
        M = 2,
        L = 4,
        XL = 8,
        XXL = 16
    };
    struct Order {
        PizzaType type;
        PizzaSize size;
        unsigned count;
    };
}

#endif /* !PLAZZA_HPP_ */
