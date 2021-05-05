/*
** EPITECH PROJECT, 2021
** main.cpp
** File description:
** main.cpp
*/

#include <iostream>
#include <unistd.h>
#include "communication/message.hpp"

#include "Kitchen.hpp"
#include "chrono/Chrono.hpp"

int main()
{
    plz::Kitchen kitchen(100);
    plz::Chrono timer;

    for (int ctr = 0; ctr < 10000;) {
        if (kitchen.getFreePlace() > 0) {
            std::cout << "Order a pizza" << std::endl;
            timer.start();
            if (kitchen.cookPizza(plz::PizzaType::Americana))
                ctr += 1;
        }
    }
    std::cout << "Finish" << std::endl;
    while (1) {
        if (kitchen.nothingToCook())
            if (timer.getElapsedTime() > 5)
                break;
    }

    /*
    Message reception;
    Message kitchen;
    std::string my_message("006");
    reception.initServer();
    kitchen.initClient();
    std::string send("009");

    int pid = fork();
    if (pid == 0) {
        std::string message;

        //message = *kitchen;
        //std::cout << "From reception: " << "[" << message << "]" << std::endl;
        kitchen << send;
        exit(0);
    } else {
        //reception << my_message;
        std::cout << "From kitchen " << "[" << *reception << "]" << std::endl;
    }
    */
    return (0);
}