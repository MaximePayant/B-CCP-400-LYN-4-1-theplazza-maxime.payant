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

    inline std::ostream& operator<<(std::ostream& os, const PizzaSize& size)
        {
            switch (size) {
                case PizzaSize::S:   os << "S";   break;
                case PizzaSize::M:   os << "M";   break;
                case PizzaSize::L:   os << "L";   break;
                case PizzaSize::XL:  os << "XL";  break;
                case PizzaSize::XXL: os << "XXL"; break;
                default:
                    os << static_cast<int>(size); break;
            }
            return (os);
        }

    inline void operator<<(PizzaSize& type, const std::string& value)
    {
        static const std::unordered_map<std::string, PizzaSize> reference =
        {
            {"S",   PizzaSize::S},
            {"M",   PizzaSize::M},
            {"L",   PizzaSize::L},
            {"XL",  PizzaSize::XL},
            {"XXL", PizzaSize::XXL}
        };

        auto it = reference.find(value);

        if (it == reference.end())
            throw std::exception();
        type = it->second;
    }

    inline void operator>>(const PizzaSize& type, std::string& value)
    {
        static const std::unordered_map<PizzaSize, std::string> reference =
        {
            {PizzaSize::S,   "S"},
            {PizzaSize::M,   "M"},
            {PizzaSize::L,   "L"},
            {PizzaSize::XL,  "XL"},
            {PizzaSize::XXL, "XXL"}
        };

        auto it = reference.find(type);

        if (it == reference.end())
            throw std::exception();
        value = it->second;
    }

    inline PizzaSize inPizzaSize(const std::string& value)
    {
        static const std::unordered_map<std::string, PizzaSize> reference =
        {
            {"S",   PizzaSize::S},
            {"M",   PizzaSize::M},
            {"L",   PizzaSize::L},
            {"XL",  PizzaSize::XL},
            {"XXL", PizzaSize::XXL}
        };

        auto it = reference.find(value);

        if (it == reference.end())
            throw std::exception();
        return (it->second);
    }

    inline std::string inStringSize(const PizzaSize& value)
    {
        static const std::unordered_map<PizzaSize, std::string> reference =
        {
            {PizzaSize::S,   "S"},
            {PizzaSize::M,   "M"},
            {PizzaSize::L,   "L"},
            {PizzaSize::XL,  "XL"},
            {PizzaSize::XXL, "XXL"}
        };

        auto it = reference.find(value);

        if (it == reference.end())
            throw std::exception();
        return (it->second);
    }

} // namespace plz

#endif // __PIZZASIZE_H__