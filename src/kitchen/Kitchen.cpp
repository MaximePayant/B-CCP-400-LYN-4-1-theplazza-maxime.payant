/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Kitchen.cpp
*/

#include "Kitchen.hpp"
#include "Cooker.hpp"

plz::Kitchen::Kitchen(unsigned cookerCount)
    :   m_cookerCount(cookerCount),
        m_pizzaWaiting(0),
        m_pizzaCooking(0),
        m_mutex(),
        m_pizzaQueue(),
        m_cookerList(),
        m_ingredientStock{
            {Tomato, 5},
            {Gruyere, 5},
            {Ham, 5},
            {Mushrooms, 5},
            {Steak, 5},
            {GoatCheese, 5},
            {EggPlant, 5}
        },
        m_serviceTimer(plz::Chrono::Wait),
        m_deliveryTimer(plz::Chrono::Wait),
        m_isWorking(true)
{
    for (unsigned ctr = 0; ctr < cookerCount; ctr += 1)
        m_cookerList.push_back(std::make_unique<plz::Cooker>(*this));
}

unsigned plz::Kitchen::getFreePlace() const
{
    return ((m_cookerCount * 2) - (m_pizzaWaiting + m_pizzaCooking));
}

void plz::Kitchen::operator()()
{
    static std::chrono::milliseconds waiting(1);

    m_deliveryTimer.start();
    while (m_isWorking) {
        std::this_thread::sleep_for(waiting);
        if (m_serviceTimer.getElapsedTime() > 5)
            m_isWorking = false;
        if (m_deliveryTimer.getElapsedTime() > 1) {
            for (auto& [_, count] : m_ingredientStock)
                count += 1;
            m_deliveryTimer.start();
        }
    }
}