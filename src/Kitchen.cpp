/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Kitchen.cpp
*/

#include "kitchen/Kitchen.hpp"

void plz::Kitchen::cookPizza(PizzaType pizza)
{
    if (m_pizzaCount + 1 > m_cookerCount * 2) {
        std::cerr << "Can't cook the pizza, the kitchen is full." << std::endl;
        return;
    }
    m_pizzaCount += 1;
    m_pizzaStack.push(pizza);
}

plz::Kitchen::Kitchen(int cookerCount)
    :   m_cookerCount(cookerCount),
        m_pizzaCount(0),
        m_pizzaStack(),
        m_cookerList()
{
    for (int ctr = 0; ctr < cookerCount; ctr += 1)
        m_cookerList.push_back(std::make_unique<ICooker>());
}

plz::Kitchen::~Kitchen()
{}

unsigned plz::Kitchen::getFreePlace()
{
    return ((m_cookerCount * 2) - m_pizzaCount);
}