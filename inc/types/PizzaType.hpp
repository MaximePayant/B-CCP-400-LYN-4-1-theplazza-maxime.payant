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

    enum class PizzaType
    {
        Nothing   = 0,
        Regina    = 1,
        Margarita = 2,
        Americana = 4,
        Fantasia  = 8
    };

}

inline std::ostream& operator<<(std::ostream& os, const plz::PizzaType& type)
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

inline plz::PizzaType inPizzaType(const std::string& value)
{
    static const std::unordered_map<std::string, plz::PizzaType> reference =
    {
        {"regina",    plz::PizzaType::Regina},
        {"margarita", plz::PizzaType::Margarita},
        {"americana", plz::PizzaType::Americana},
        {"fantasia",  plz::PizzaType::Fantasia}
    };

    auto it = reference.find(value);

    if (it == reference.end())
        throw std::exception();
    return (it->second);
}

inline std::string inStringType(const plz::PizzaType& value)
{
    static const std::unordered_map<plz::PizzaType, std::string> reference =
    {
        {plz::PizzaType::Regina,    "regina"},
        {plz::PizzaType::Margarita, "margarita"},
        {plz::PizzaType::Americana, "americana"},
        {plz::PizzaType::Fantasia,  "fantasia"}
    };

    auto it = reference.find(value);

    if (it == reference.end())
        throw std::exception();
    return (it->second);
}

#endif // __PIZZATYPE_H__