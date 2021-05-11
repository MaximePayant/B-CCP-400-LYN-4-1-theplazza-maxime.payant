/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** receptionCom.cpp
*/

#include "Kitchen.hpp"

unsigned plz::Kitchen::getFreePlace() const
{
    return ((m_cookerCount * 2) - (m_pizzaWaiting + m_pizzaCooking));
}

void plz::Kitchen::checkOrder(const std::string& message)
{
    (void)message;
}

bool plz::Kitchen::cookPizza(PizzaType pizza)
{
    if ((m_pizzaWaiting + m_pizzaCooking) + 1 > m_cookerCount * 2) {
        std::cerr << "Can't cook the pizza, the kitchen is full." << std::endl;
        return (false);
    }

    std::unique_lock<std::mutex> locker(m_mutex);

    m_pizzaWaiting += 1;
    m_pizzaQueue.push(pizza);
    m_serviceTimer.stop();
    return (true);
}