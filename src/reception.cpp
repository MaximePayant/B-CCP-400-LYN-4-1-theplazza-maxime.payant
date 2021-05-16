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
{}

static int getStatut(const std::string& message)
{
    if (message.empty())
        return (-1);
    return (std::stoul(message));
}

void plz::Reception::checkStatusKitchen()
{
    std::string message("freePlace");

    m_listStatusKitchen.erase(m_listStatusKitchen.begin(), m_listStatusKitchen.end());
    std::cout << "messengerList size : " << m_messengerList.size() << std::endl;
    for (int ctr = 0; auto& messenger : m_messengerList) {
        std::cout << "Send message to kitchen n°" << ctr << " to get status" << std::endl;
        std::cout << "Reception:" << std::endl << messenger;
        messenger << message;
        ctr += 1;
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(2));

    for (auto it = m_messengerList.begin(); auto& messenger : m_messengerList) {
        messenger >> message;
        int statut = getStatut(message);
        if (statut == -1) {
            it = m_messengerList.erase(it);
            m_nbrKitchen -= 1;
        }
        else {
            m_listStatusKitchen.push_back(statut);
            it++;
        }
    }
}

void plz::Reception::getStatus()
{
    std::string message("status");

    checkStatusKitchen();
    for (auto& messenger : m_messengerList)
        messenger << message;

    std::this_thread::sleep_for(std::chrono::milliseconds(2));

    for (auto& messenger : m_messengerList) {
        messenger >> message;
        std::cout << message << std::endl;
    }
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
        m_nbrKitchen += 1;
    }
    return (1);
}

int plz::Reception::findKitchen()
{
    int index = -1;
    int idxVal = -1;

    for(int ctr = 0; auto &elem : m_listStatusKitchen) {
        std::cout << elem << " free place for kitchen n°" << ctr << std::endl;
        if (elem > 0 && elem > idxVal) {
            idxVal = elem;
            index = ctr;
        }
        ctr += 1;
    }
    if (index == -1) {
        std::cout << "Create kitchen" << std::endl;
        index = m_nbrKitchen;
        createKitchen();
    }
    return (index);
}

void plz::Reception::sendOrder(unsigned kitchenTarget, plz::PizzaType pizzaType)
{
    std::string type = inStringType(pizzaType);

    std::cout << "Order a " << type << " for kitchen n°" << kitchenTarget << std::endl;
    m_messengerList.at(kitchenTarget).sendMessage(type);
}

int plz::Reception::takeOrder(plz::Order order)
{
    unsigned kitchenTarget;

    std::cout << "Order " << order.count << " " << order.type << std::endl;

    while (order.count > 0) {
        checkStatusKitchen();
        kitchenTarget = findKitchen();
        sendOrder(kitchenTarget, order.type);
        std::cout << "Sent" << std::endl;
        order.count -= 1;
        std::cout << "----------" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(2));
    }
    return (0);
}