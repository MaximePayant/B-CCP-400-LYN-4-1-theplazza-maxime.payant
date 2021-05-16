/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Cooker.cpp
*/

#include "Cooker.hpp"
#include "shell.hpp"

plz::Cooker::Cooker(IKitchen& kitchen)
    :   m_kitchen(kitchen),
        m_thread(
            [this](std::stop_token token) {
                while (!token.stop_requested())
                    this->workHard();
            }
        ),
        m_order(plz::PizzaType::Nothing),
        m_timer(plz::Chrono::Wait),
        m_statut(HasNothing)
{
    plz::writeLog("Cook ready to work !");
}

plz::Cooker::~Cooker()
{
    plz::writeLog("Cook expulsed...");
}

void plz::Cooker::workHard()
{
    static std::chrono::milliseconds waiting(1);

    std::this_thread::sleep_for(waiting);
    if (m_statut == HasNothing) {
        m_order = m_kitchen.getNextOrder();
        if (m_order != plz::PizzaType::Nothing) {
            m_timer.start();
            m_statut = Cooking;
        }
    }
    if (m_statut == Cooking) {
        while (m_timer.getElapsedTime() < plz::pizzaTime[m_order] * plz::Shell::cookerMultiplier)
            std::this_thread::sleep_for(waiting);
        m_kitchen.finishPizza(m_order);
        m_statut = HasNothing;
    }
}