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
        Doe,
        Tomato,
        Gruyere,
        Ham,
        Mushrooms,
        Steak,
        GoatCheese,
        EggPlant,
        ChiefLove,
        END
    };

    inline std::ostream& operator<<(std::ostream& os, const Ingredient& type)
    {
        switch (type) {
            case Ingredient::Doe:        os << "Doe";        break;
            case Ingredient::Tomato:     os << "Tomato";     break;
            case Ingredient::Gruyere:    os << "Gruyere";    break;
            case Ingredient::Ham:        os << "Ham";        break;
            case Ingredient::Mushrooms:  os << "Mushrooms";  break;
            case Ingredient::Steak:      os << "Steak";      break;
            case Ingredient::GoatCheese: os << "GoatCheese"; break;
            case Ingredient::EggPlant:   os << "EggPlant";   break;
            case Ingredient::ChiefLove:  os << "ChiefLove";  break;
            default:
                os << static_cast<int>(type); break;
        }
        return (os);
    }

} // namespace plz


#endif // __INGREDIENT_H__