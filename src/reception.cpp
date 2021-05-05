/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Reception
*/

#include "reception.hpp"

std::vector<int> plz::Reception::checkStatusKitchen()
{
    std::vector<int> listStatusKitchen;
    int statusKitchen;

    listStatusKitchen.push_back(5);
    listStatusKitchen.push_back(3);
    listStatusKitchen.push_back(1);
    listStatusKitchen.push_back(2);
    return listStatusKitchen;
}

int plz::Reception::findKitchen()
{
    int status = 0;
    for(auto & elem : this->listStatusKitchen)
        if (elem > status)
            elem = status;
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
}

void plz::Reception::sendOrder(int kitchenTarget, int type)
{
    std::cout << type << std::endl;
}

plz::Reception::Reception(std::queue<Order> listOrder)
{
    int kitchenTarget;
    this->listStatusKitchen = checkStatusKitchen();
    std::cout << listOrder.front().count << std::endl;
    while (listOrder.front().count != 0 && listOrder.size() != 0) {
        kitchenTarget = findKitchen();
        sendOrder(kitchenTarget, listOrder.front().type); 
        listOrder = deleteOrder(listOrder);
    }
//    while (!this->listOrder.empty())
//        this->listOrder.pop();
//    while (!listOrder.empty())
//        listOrder.pop();
    std::cout << std::endl;
//    std::cout << listOrder.front().count << std::endl << std::endl;
   
}

plz::Reception::~Reception()
{
}
