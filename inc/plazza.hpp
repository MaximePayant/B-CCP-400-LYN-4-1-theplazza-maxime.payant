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
        Nothing   = 0,
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

} // namespace plz

inline std::ostream& operator<<(std::ostream& os, plz::PizzaType& type)
{
    switch (type) {
        case plz::PizzaType::Nothing:   os << "Nothing";   break;
        case plz::PizzaType::Regina:    os << "Regina";    break;
        case plz::PizzaType::Margarita: os << "Margarita"; break;
        case plz::PizzaType::Americana: os << "Americana"; break;
        case plz::PizzaType::Fantasia:  os << "Fantasia";  break;
    }
    return (os);
}

inline std::ostream& operator<<(std::ostream& os, plz::PizzaSize& size)
{
    switch (size) {
        case plz::PizzaSize::S:   os << "S";   break;
        case plz::PizzaSize::M:   os << "M";   break;
        case plz::PizzaSize::L:   os << "L";   break;
        case plz::PizzaSize::XL:  os << "XL";  break;
        case plz::PizzaSize::XXL: os << "XXL"; break;
    }
    return (os);
}

inline std::ostream& operator<<(std::ostream& os, plz::Order& order)
{
    os << "For table 55 :"    << std::endl
       << "\t" << order.type  << std::endl
       << "\t" << order.size  << std::endl
       << "\t" << order.count << std::endl;
    return (os);
}

#endif /* !PLAZZA_HPP_ */
