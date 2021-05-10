/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Reception
*/

#include "reception.hpp"
#include "Kitchen.hpp"
#include "shell.hpp"


std::vector<int> plz::Reception::checkStatusKitchen()
{
    std::vector<int> listStatusKitchen;

    listStatusKitchen.push_back(0);
    listStatusKitchen.push_back(0);
    listStatusKitchen.push_back(2);
    listStatusKitchen.push_back(0);
    return listStatusKitchen;
}

int plz::Reception::createKitchen()
{
    pid_t c_pid = fork();

    if (c_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (c_pid == 0) {
//        std::cout << "chil process " << getpid() << std::endl;
        plz::Kitchen kitchen(plz::Shell::cooksNumber);
        exit (0);
    }
    return (1);
}

int plz::Reception::findKitchen()
{
    int status = 0;
    for(auto & elem : this->listStatusKitchen)
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
    this->listStatusKitchen = checkStatusKitchen();
    //
    std::cout << listOrder.front().count << std::endl;
    while (listOrder.front().count != 0 && listOrder.size() != 0) {
        kitchenTarget = findKitchen();
        sendOrder(kitchenTarget, listOrder.front().type);
        listOrder = deleteOrder(listOrder);
    }
    std::cout << std::endl;
    return (0);
}

plz::Reception::Reception()
{

}

plz::Reception::~Reception()
{
}
