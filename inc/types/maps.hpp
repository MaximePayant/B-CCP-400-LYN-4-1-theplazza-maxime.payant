/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** maps.hpp
*/

#ifndef __MAPS_H__
#define __MAPS_H__

#include <set>
#include <unordered_map>
#include "Ingredient.hpp"
#include "PizzaType.hpp"

namespace plz
{

    static std::unordered_map<PizzaType, unsigned> pizzaTime =
    {
        {PizzaType::Margarita, 1},
        {PizzaType::Regina,    2},
        {PizzaType::Americana, 2},
        {PizzaType::Fantasia,  4}
    };

    static std::unordered_map<PizzaType, std::set<Ingredient>> pizzaRecipe =
    {
        {PizzaType::Margarita, {Ingredient::Doe, Ingredient::Tomato, Ingredient::Gruyere                                                }},
        {PizzaType::Regina,    {Ingredient::Doe, Ingredient::Tomato, Ingredient::Gruyere,  Ingredient::Ham,        Ingredient::Mushrooms}},
        {PizzaType::Americana, {Ingredient::Doe, Ingredient::Tomato, Ingredient::Gruyere,  Ingredient::Steak                            }},
        {PizzaType::Fantasia,  {Ingredient::Doe, Ingredient::Tomato, Ingredient::EggPlant, Ingredient::GoatCheese, Ingredient::ChiefLove}}
    };

} // namespace plz

#endif // __MAPS_H__