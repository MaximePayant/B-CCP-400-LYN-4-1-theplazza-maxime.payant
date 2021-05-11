/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Reception
*/

#include "reception.hpp"
#include "Kitchen.hpp"
#include "shell.hpp"
#include "communication/message.hpp"


int plz::Reception::recupMessageStatus(Message message)
{
    (void)message;
    return (0);
}

void plz::Reception::checkStatusKitchen()
{
    std::string message("swdfx njlk,;");

    for (unsigned i = 0; i < m_nbrKitchen; i += 1){
        m_listReceptionMessage.at(i).sendMessage(message);
        std::cout << "Message sent! (" << message << ")" << std::endl;
    }
//    for (unsigned i = 0; i < m_nbrKitchen; i++)
  //      listStatusKitchen.push_back(recupMessageStatus(listKitchenMessage.at(nbrKitchen)));

    Message reception_1(1);
    Message kitchen_1(1);
    Message reception_2(2);
    Message kitchen_2(2);
    std::string my_message("006");
    std::string send("009");

    int pid = fork();
    if (pid == 0) {
        std::string message;

        message = *kitchen_1;
        std::cout << "From reception(fork 1): " << "[" << message << "]" << std::endl;
        //kitchen_1 << send;
        exit(0);
    }
    pid = fork();
    if (pid == 0) {
        std::string message;

        message = *kitchen_2;
        std::cout << "From reception(fork 2): " << "[" << message << "]" << std::endl;
        //kitchen << send;
        exit(0);
    }
    reception_1 << send;
    reception_2 << send;
    std::cout << "From kitchen " << "[" << *reception_1 << "]" << std::endl;

}

int plz::Reception::createKitchen()
{
    pid_t c_pid = fork();

    if (c_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (c_pid == 0) {
        plz::Kitchen kitchen(plz::Shell::cooksNumber, m_nbrKitchen);
        kitchen();
        exit (0);
    }
    else {
        Message receptionMess(m_nbrKitchen);
        Message kitchenMess(m_nbrKitchen);
        m_listReceptionMessage.push_back(receptionMess);
        m_listKitchenMessage.push_back(kitchenMess);
        m_listStatusKitchen.push_back(plz::Shell::cooksNumber);
        m_nbrKitchen += 1;
    }
    return (1);
}

int plz::Reception::findKitchen()
{
    int status = 0;
    for(auto & elem : m_listStatusKitchen)
        if (elem > status) {
            status = elem;
            elem --;
        }
    if (status == 0) {
        createKitchen();
    }
    return status;
}

std::queue<plz::Order> plz::Reception::deleteOrder(std::queue<Order> listOrder)
{
    if (listOrder.front().count > 1) {
        listOrder.front().count --;
        return (listOrder);
    }
    if (listOrder.front().count == 1) {
        listOrder.pop();
        return (listOrder);
    }
    return (listOrder);
}

void plz::Reception::sendOrder(int kitchenTarget, int type)
{
    std::cout << type << std::endl;
    (void)kitchenTarget;
}

int plz::Reception::exec(std::queue<Order> listOrder)
{
    int kitchenTarget;
    checkStatusKitchen();

    std::cout << "nbrKitchen : " << m_nbrKitchen << std::endl
                << "listReceptionMessage : " << m_listReceptionMessage.size() << std::endl
                << "listKitchenMessage : " << m_listKitchenMessage.size() << std::endl;

    while (listOrder.size() != 0) {
        kitchenTarget = findKitchen();
        sendOrder(kitchenTarget, listOrder.front().type);
        listOrder = deleteOrder(listOrder);
    }
    std::cout << std::endl;
    return (0);
}

plz::Reception::Reception()
    :   m_listStatusKitchen(),
        m_listReceptionMessage(),
        m_listKitchenMessage(),
        m_listOrder(),
        m_nbrKitchen(0)
{
    createKitchen();
}

plz::Reception::~Reception()
{
}
