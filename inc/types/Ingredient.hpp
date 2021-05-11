/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Ingredient.hpp
*/

#ifndef __INGREDIENT_H__
#define __INGREDIENT_H__

#include <iostream>

namespace plz
{

    enum Ingredient
    {
        Tomato,
        Gruyere,
        Ham,
        Mushrooms,
        Steak,
        GoatCheese,
        EggPlant,
        ChiefLove
    };

} // namespace plz

inline std::ostream& operator<<(std::ostream& os, const plz::Ingredient& type)
{
    switch (type) {
        case plz::Ingredient::Tomato:     os << "Tomato";     break;
        case plz::Ingredient::Gruyere:    os << "Gruyere";    break;
        case plz::Ingredient::Ham:        os << "Ham";        break;
        case plz::Ingredient::Mushrooms:  os << "Mushrooms";  break;
        case plz::Ingredient::Steak:      os << "Steak";      break;
        case plz::Ingredient::GoatCheese: os << "GoatCheese"; break;
        case plz::Ingredient::EggPlant:   os << "EggPlant";   break;
        case plz::Ingredient::ChiefLove:  os << "ChiefLove";  break;
    }
    return (os);
}

#endif // __INGREDIENT_H__