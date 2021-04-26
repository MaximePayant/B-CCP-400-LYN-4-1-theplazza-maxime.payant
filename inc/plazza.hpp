/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** plazza
*/

#ifndef PLAZZA_HPP_
#define PLAZZA_HPP_

#include <unordered_map>
#include <iostream>

namespace plz
{

    enum PizzaType
    {
        Regina    = 1,
        Margarita = 2,
        Americana = 4,
        Fantasia  = 8
    };

    enum PizzaSize
    {
        S   = 1,
        M   = 2,
        L   = 4,
        XL  = 8,
        XXL = 16
    };

    struct Order
    {
        PizzaType type;
        PizzaSize size;
        unsigned  count;
    };

    static std::unordered_map<PizzaType, unsigned> pizzaTime =
    {
        {PizzaType::Margarita, 1},
        {PizzaType::Regina,    2},
        {PizzaType::Americana, 2},
        {PizzaType::Fantasia,  4}
    };

}; // namespace plz

#endif /* !PLAZZA_HPP_ */
