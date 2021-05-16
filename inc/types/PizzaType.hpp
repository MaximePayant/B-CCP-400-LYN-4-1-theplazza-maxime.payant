/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** PizzaType.hpp
*/

#ifndef __PIZZATYPE_H__
#define __PIZZATYPE_H__

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

    inline std::ostream& operator<<(std::ostream& os, const PizzaType& type)
    {
        switch (type) {
            case PizzaType::Nothing:   os << "Nothing";   break;
            case PizzaType::Regina:    os << "Regina";    break;
            case PizzaType::Margarita: os << "Margarita"; break;
            case PizzaType::Americana: os << "Americana"; break;
            case PizzaType::Fantasia:  os << "Fantasia";  break;
            default:
                os << static_cast<int>(type); break;
        }
        return (os);
    }

    inline void operator<<(PizzaType& type, const std::string& value)
    {
        static const std::unordered_map<std::string, PizzaType> reference =
        {
            {"regina",    PizzaType::Regina},
            {"margarita", PizzaType::Margarita},
            {"americana", PizzaType::Americana},
            {"fantasia",  PizzaType::Fantasia}
        };

        auto it = reference.find(value);

        if (it == reference.end())
            throw std::exception();
        type = it->second;
    }

    inline void operator>>(const PizzaType& type, std::string& value)
    {
        static const std::unordered_map<PizzaType, std::string> reference =
        {
            {PizzaType::Regina,    "regina"},
            {PizzaType::Margarita, "margarita"},
            {PizzaType::Americana, "americana"},
            {PizzaType::Fantasia,  "fantasia"}
        };

        auto it = reference.find(type);

        if (it == reference.end())
            throw std::exception();
        value = it->second;
    }

    inline PizzaType inPizzaType(const std::string& value)
    {
        static const std::unordered_map<std::string, PizzaType> reference =
        {
            {"regina",    PizzaType::Regina},
            {"margarita", PizzaType::Margarita},
            {"americana", PizzaType::Americana},
            {"fantasia",  PizzaType::Fantasia}
        };

        auto it = reference.find(value);

        if (it == reference.end())
            throw std::exception();
        return (it->second);
    }

    inline std::string inStringType(const PizzaType& value)
    {
        static const std::unordered_map<PizzaType, std::string> reference =
        {
            {PizzaType::Regina,    "regina"},
            {PizzaType::Margarita, "margarita"},
            {PizzaType::Americana, "americana"},
            {PizzaType::Fantasia,  "fantasia"}
        };

        auto it = reference.find(value);

        if (it == reference.end())
            throw std::exception();
        return (it->second);
    }

} // namespace plz

#endif // __PIZZATYPE_H__