/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** PizzaSize.hpp
*/

#ifndef __PIZZASIZE_H__
#define __PIZZASIZE_H__

#include <iostream>

namespace plz
{

    enum PizzaSize
    {
        S   = 1,
        M   = 2,
        L   = 4,
        XL  = 8,
        XXL = 16
    };

}

inline std::ostream& operator<<(std::ostream& os, const plz::PizzaSize& size)
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

inline plz::PizzaSize inPizzaSize(const std::string& value)
{
    static const std::unordered_map<std::string, plz::PizzaSize> reference =
    {
        {"S",   plz::PizzaSize::S},
        {"M",   plz::PizzaSize::M},
        {"L",   plz::PizzaSize::L},
        {"XL",  plz::PizzaSize::XL},
        {"XXL", plz::PizzaSize::XXL}
    };

    auto it = reference.find(value);

    if (it == reference.end())
        throw std::exception();
    return (it->second);
}

inline std::string inStringSize(const plz::PizzaSize& value)
{
    static const std::unordered_map<plz::PizzaSize, std::string> reference =
    {
        {plz::PizzaSize::S,   "S"},
        {plz::PizzaSize::M,   "M"},
        {plz::PizzaSize::L,   "L"},
        {plz::PizzaSize::XL,  "XL"},
        {plz::PizzaSize::XXL, "XXL"}
    };

    auto it = reference.find(value);

    if (it == reference.end())
        throw std::exception();
    return (it->second);
}

#endif // __PIZZASIZE_H__