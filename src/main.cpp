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
    plz::Kitchen kitchen(10);
    plz::Chrono timer;

    for (int ctr = 0; ctr < 20;) {
        kitchen.cookPizza(plz::PizzaType::Americana);
        ctr += 1;
    }
    kitchen();

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