/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** receptionCom.cpp
*/

#include <sstream>

#include "Kitchen.hpp"

unsigned plz::Kitchen::getFreePlace() const
{
    return ((m_cookerCount * 2) - (m_pizzaWaiting + m_pizzaCooking));
}

std::string plz::Kitchen::getStatus() const
{
    std::stringstream sstream;

    sstream << " - Cookers: "       << m_cookerCount  << std::endl
            << " - Free place: "    << getFreePlace() << std::endl
            << " - Pizza cooking: " << m_pizzaCooking << std::endl
            << " - Pizza waiting: " << m_pizzaWaiting << std::endl
            << " - Pizza cooked: "  << m_pizzaCooked  << std::endl
            << " - Ingredients:"    << std::endl;
    for (auto& [ing, count] : m_ingredientStock)
        sstream << "      " << ing << ": " << count << std::endl;
    sstream << " - Next delivery in: "  << m_deliveryTimer.getElapsedTime() << std::endl;
    if (!m_pizzaWaiting && !m_pizzaCooking)
        sstream << " - End of service in: " << m_serviceTimer.getElapsedTime() << std::endl;
    else
        sstream << " - End of service in: NEVER!" << std::endl;
    return (sstream.str());
}

void plz::Kitchen::checkOrder(const std::string& message)
{
    if (message == "status") {
        std::string str = getStatus();
        m_messenger << str;
    }
    else if (message == "freePlace") {
        std::string str = std::to_string(getFreePlace()) + ";";
        m_messenger << str;
    }
    else
        cookPizza(inPizzaType(message));
}

bool plz::Kitchen::cookPizza(plz::PizzaType pizza)
{
    std::unique_lock<std::mutex> locker(m_mutex);

    if ((m_pizzaWaiting + m_pizzaCooking) + 1 > m_cookerCount * 2) {
        std::cerr << "Can't cook the pizza, the kitchen is full." << std::endl;
        return (false);
    }

    plz::writeLog("Kitchen n°" + std::to_string(m_id) + ": get a new order - " + plz::inStringType(pizza) + " ; add to the list.");
    m_pizzaWaiting += 1;
    m_pizzaQueue.push(pizza);
    m_serviceTimer.stop();
    return (true);
}