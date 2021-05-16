/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Kitchen.cpp
*/

#include <sys/types.h>
#include <unistd.h>

#include "Kitchen.hpp"
#include "Cooker.hpp"
#include "shell.hpp"

plz::Kitchen::Kitchen(unsigned id)
    :   m_id(id),
        m_messenger(id, MSG_RECEPTION, MSG_KITCHEN),
        m_cookerCount(plz::Shell::cooksNumber),
        m_pizzaWaiting(0),
        m_pizzaCooking(0),
        m_mutex(),
        m_pizzaQueue(),
        m_cookerList(),
        m_ingredientStock{},
        m_serviceTimer(plz::Chrono::Wait),
        m_deliveryTimer(plz::Chrono::Wait),
        m_isWorking(true),
        m_pizzaCooked(0)
{
    plz::writeLog("Kitchen n°" + std::to_string(m_id) + " is now open !");
    for (int ctr = 0; ctr < plz::Ingredient::END; ctr += 1)
        m_ingredientStock[static_cast<plz::Ingredient>(ctr)] = 5;
    for (unsigned ctr = 0; ctr < m_cookerCount; ctr += 1)
        m_cookerList.push_back(std::make_unique<plz::Cooker>(*this));
}

plz::Kitchen::~Kitchen()
{
    plz::writeLog("Kitchen n°" + std::to_string(m_id) + " close because of some sanitary problem ^^'");
}

void plz::Kitchen::operator()()
{
    static std::chrono::milliseconds waiting(1);
    std::string message = "";

    m_deliveryTimer.start();
    while (m_isWorking) {
        std::this_thread::sleep_for(waiting);
        m_messenger >> message;
        if (m_deliveryTimer.getElapsedTime() > plz::Shell::refillTime) {
            for (auto& [_, count] : m_ingredientStock)
                count += 1;
            m_deliveryTimer.start();
        }
        if (m_serviceTimer.getElapsedTime() > 5)
            m_isWorking = false;
        else if (!message.empty())
            checkOrder(message);
    }
}