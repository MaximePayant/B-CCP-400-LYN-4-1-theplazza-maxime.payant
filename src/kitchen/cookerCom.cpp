/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** cookerCom.cpp
*/

#include <thread>

#include "Kitchen.hpp"
#include "shell.hpp"

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
    std::unique_lock<std::mutex> locker(m_mutex);

    if (!m_pizzaWaiting || m_pizzaQueue.empty())
        return (plz::PizzaType::Nothing);

    plz::PizzaType order = m_pizzaQueue.front();

    if (order == plz::PizzaType::Nothing || !gatherIngredient(order))
        return (plz::PizzaType::Nothing);
    plz::writeLog("Kitchen n°" + std::to_string(m_id) + ": Cooker take " + plz::inStringType(order) + " to cook.");
    m_pizzaQueue.pop();
    m_pizzaWaiting -= 1;
    m_pizzaCooking += 1;
    return (order);
}

void plz::Kitchen::finishPizza(PizzaType type)
{
    std::unique_lock<std::mutex> locker(m_mutex);

    plz::writeLog("Kitchen n°" + std::to_string(m_id) + ": " + plz::inStringType(type) + " cooked !");
    m_pizzaCooking -= 1;
    m_pizzaCooked += 1;
    if (!m_pizzaWaiting
    && !m_pizzaCooking)
        m_serviceTimer.start();
}