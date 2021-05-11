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

void plz::Kitchen::checkOrder(const std::string& message)
{
    //std::cout << "Kitchen recieve : <" << message << ">" << std::endl;
    if (message == "status") {
        std::stringstream sstream;
        sstream << "Cookers: "       << m_cookerCount  << std::endl
                << "Free place: "    << getFreePlace() << std::endl
                << "Pizza cooking: " << m_pizzaCooking << std::endl
                << "Pizza waiting: " << m_pizzaWaiting << std::endl;
        for (auto& [ing, count] : m_ingredientStock)
            sstream << ing << ": " << count << std::endl;
        sstream << "Next delivery in: "  << m_deliveryTimer.getElapsedTime() << std::endl;
        if (m_isWorking)
            sstream << "End of service in: NEVER!" << std::endl;
        else
            sstream << "End of service in: " << m_serviceTimer.getElapsedTime() << std::endl;
        std::string str = sstream.str();
        m_messenger << str;
    }
    else if (message == "freePlace") {
        std::string str = std::to_string(getFreePlace()) + ";";
        m_messenger << str;
    }
    else
        cookPizza(inPizzaType(message));
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