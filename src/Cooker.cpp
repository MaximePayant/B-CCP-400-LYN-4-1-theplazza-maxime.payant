/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Cooker.cpp
*/

#include "Cooker.hpp"

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
{}

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
        while (m_timer.getElapsedTime() < plz::pizzaTime[m_order])
            std::this_thread::sleep_for(waiting);
        m_kitchen.finishPizza();
        m_statut = HasNothing;
    }
}