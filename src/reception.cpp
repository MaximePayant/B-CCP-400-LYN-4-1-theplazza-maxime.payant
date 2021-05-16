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
    for (int ctr = 0; auto& messenger : m_messengerList) {
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

    for (int ctr = 0; auto& messenger : m_messengerList) {
        std::cout << "Kitchen n°" << ctr << ":" << std::endl;
        messenger >> message;
        std::cout << message << std::endl;
    }
}

static void childProcess(int index)
{
    plz::Kitchen kitchen(index);
    kitchen();
}

int plz::Reception::createKitchen()
{
    pid_t c_pid = fork();

    if (c_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (c_pid == 0) {
        childProcess(m_nbrKitchen);
        _exit(0);
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
        if (elem > 0 && elem > idxVal) {
            idxVal = elem;
            index = ctr;
        }
        ctr += 1;
    }
    if (index == -1) {
        index = m_nbrKitchen;
        createKitchen();
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
        std::this_thread::sleep_for(std::chrono::milliseconds(2));
    }
    return (0);
}