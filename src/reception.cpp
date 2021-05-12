/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Reception
*/

#include <thread>
#include <unistd.h>

#include "reception.hpp"
#include "Kitchen.hpp"
#include "shell.hpp"
#include "communication/message.hpp"

plz::Reception::Reception()
    :   m_listStatusKitchen(),
        m_messengerList(),
        m_listOrder(),
        m_nbrKitchen(0)
{
}

static int getStatut(const std::string& message)
{
    if (message.empty())
        return (-1);
    return (std::stoul(message));
}

void plz::Reception::checkStatusKitchen()
{
    std::string message("freePlace");

    //std::cout << "Size messanger list: " << m_messengerList.size() << std::endl;
    for (auto& messenger : m_messengerList)
        messenger << message;
    std::this_thread::sleep_for(std::chrono::milliseconds(2));
    m_listStatusKitchen.erase(m_listStatusKitchen.begin(), m_listStatusKitchen.end());
    for (auto it = m_messengerList.begin(); auto& messenger : m_messengerList) {
        int statut = getStatut(*messenger);
        //std::cout << "Statut n°" << ctr << " - " << statut << std::endl;
        if (statut == -1)
            m_messengerList.erase(it);
        else
            m_listStatusKitchen.push_back(statut);
        it++;
    }
}

void plz::Reception::getStatus()
{
    std::string message("status");

    checkStatusKitchen();
    for (auto& sender : m_messengerList)
        sender << message;
    std::this_thread::sleep_for(std::chrono::milliseconds(2));
    for (auto& sender : m_messengerList)
        std::cout << *sender << std::endl;
}

int plz::Reception::createKitchen()
{
    pid_t c_pid = fork();

    if (c_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (c_pid == 0) {
        plz::Kitchen kitchen(m_nbrKitchen);
        kitchen();
        exit(0);
    }
    else {
        m_messengerList.emplace_back(m_nbrKitchen, MSG_KITCHEN, MSG_RECEPTION);
        m_listStatusKitchen.emplace_back(plz::Shell::cooksNumber);
        m_nbrKitchen += 1;
    }
    return (1);
}

int plz::Reception::findKitchen()
{
    int index = -1;

    //std::cout << "Size statut list: " << m_listStatusKitchen.size() << std::endl;
    for(int ctr = 0; auto &elem : m_listStatusKitchen) {
        //std::cout << "lol" << std::endl;
        if (elem > index)
            index = ctr;
        ctr += 1;
    }
    //std::cout << "index: " << index << std::endl;
    if (index == -1) {
        createKitchen();
        index = 0;
    }
    return (index);
}

void plz::Reception::sendOrder(unsigned kitchenTarget, plz::PizzaType pizzaType)
{
    std::string type = inStringType(pizzaType);

    m_messengerList.at(kitchenTarget).sendMessage(type);
}

int plz::Reception::takeOrder(plz::Order order)
{
    unsigned kitchenTarget;

    while (order.count > 0) {
        checkStatusKitchen();
        kitchenTarget = findKitchen();
        sendOrder(kitchenTarget, order.type);
        order.count -= 1;
    }
    return (0);
}