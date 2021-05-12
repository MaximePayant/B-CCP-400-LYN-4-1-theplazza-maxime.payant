/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** cookerCom.cpp
*/

#include "Kitchen.hpp"

static bool hasIngredient(std::unordered_map<plz::Ingredient, unsigned> ingredientStock,
                          std::set<plz::Ingredient> neededIngredient)
{
    for (auto& igd : neededIngredient)
        if (!ingredientStock[igd])
            return (false);
    return (true);
}

bool plz::Kitchen::gatherIngredient(plz::PizzaType type)
{
    if (!hasIngredient(m_ingredientStock, pizzaRecipe[type]))
        return (false);
    for (auto& igd : pizzaRecipe[type])
        m_ingredientStock[igd] -= 1;
    return (true);
}

plz::PizzaType plz::Kitchen::getNextOrder()
{
    if (!m_pizzaWaiting)
        return (plz::PizzaType::Nothing);

    std::unique_lock<std::mutex> locker(m_mutex);
    plz::PizzaType order = m_pizzaQueue.front();

    if (!gatherIngredient(order) || order == plz::PizzaType::Nothing)
        return (plz::PizzaType::Nothing);
    m_pizzaQueue.pop();
    m_pizzaWaiting -= (!m_pizzaWaiting ? 0 : 1);
    m_pizzaCooking += 1;
    return (order);
}

void plz::Kitchen::finishPizza()
{
    std::unique_lock<std::mutex> locker(m_mutex);

    m_pizzaCooking -= (!m_pizzaCooking ? 0 : 1);
    if (!m_pizzaWaiting
    && !m_pizzaCooking)
        m_serviceTimer.start();
}