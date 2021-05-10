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
        //kitchen << send;
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
    reception_1 << my_message;
    reception_2 << send;
    //std::cout << "From kitchen " << "[" << *reception << "]" << std::endl;
    /*plz::Kitchen kitchen(10);
    plz::Chrono timer;

    for (int ctr = 0; ctr < 20;) {
        kitchen.cookPizza(plz::PizzaType::Americana);
        ctr += 1;
    }
    kitchen();*/

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
    }*/
}