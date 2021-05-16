/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Order.hpp
*/

#ifndef __ORDER_H__
#define __ORDER_H__

#include "PizzaSize.hpp"
#include "PizzaType.hpp"

namespace plz
{

    struct Order
    {
        PizzaType type;
        PizzaSize size;
        unsigned  count;
    };

    inline std::ostream& operator<<(std::ostream& os, const Order& order)
    {
        os << "For table 55 :"    << std::endl
           << "\t" << order.type  << std::endl
           << "\t" << order.size  << std::endl
           << "\t" << order.count << std::endl;
        return (os);
    }

}

#endif // __ORDER_H__