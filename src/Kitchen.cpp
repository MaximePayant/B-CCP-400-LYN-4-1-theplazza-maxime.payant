/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Kitchen.cpp
*/

#include "Kitchen.hpp"
#include "Cooker.hpp"

plz::Kitchen::Kitchen(int cookerCount)
    :   m_cookerCount(cookerCount),
        m_pizzaCount(0),
        m_pizzaStack(),
        m_cookerList()
{
    for (int ctr = 0; ctr < cookerCount; ctr += 1)
        m_cookerList.push_back(std::make_unique<plz::Cooker>(*this));
}

bool plz::Kitchen::cookPizza(PizzaType pizza)
{
    if (m_pizzaCount + 1 > m_cookerCount * 2) {
        std::cerr << "Can't cook the pizza, the kitchen is full." << std::endl;
        return (false);
    }

    std::unique_lock<std::mutex> locker(m_mutex);

    m_pizzaCount += 1;
    m_pizzaStack.push(pizza);
    return (true);
}

unsigned plz::Kitchen::getFreePlace()
{
    return ((m_cookerCount * 2) - m_pizzaCount);
}

plz::PizzaType plz::Kitchen::getNextOrder()
{
    if (!m_pizzaCount)
        return (plz::PizzaType::Nothing);

    std::unique_lock<std::mutex> locker(m_mutex);
    plz::PizzaType order = m_pizzaStack.front();

    m_pizzaStack.pop();
    m_pizzaCount -= 1;
    return (order);
}

bool plz::Kitchen::nothingToCook()
{
    if (m_pizzaCount == 0)
        return (true);
    return (false);
}