/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Cooker.cpp
*/

#include "Cooker.hpp"

plz::Cooker::Cooker(IKitchen& kitchen)
    :   m_kitchen(kitchen),
        m_stopSrc(),
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
    if (m_statut == Cooking) {
        while (m_timer.getElapsedTime() < plz::pizzaTime[m_order]);
        std::cout << m_order << " is cooked !" << std::endl;
        m_statut = HasNothing;
    }
    if (m_statut == HasNothing) {
        m_order = m_kitchen.getNextOrder();
        if (m_order != plz::PizzaType::Nothing) {
            m_timer.start();
            m_statut = Cooking;
        }
    }
}

bool plz::Cooker::isCooking()
{
    if (m_statut == Cooking)
        return (true);
    return (false);
}