/*
** EPITECH PROJECT, 2021
** main.cpp
** File description:
** main.cpp
*/

#include <iostream>
#include <unistd.h>
#include "communication/message.hpp"

int main()
{
    Message reception;
    Message kitchen;
    std::string my_message("006");
    reception.initServer();
    kitchen.initClient();

    int pid = fork();
    if (pid == 0) {
        std::string message;
        std::string send("009");

        //message = *kitchen;
        //std::cout << "From reception: " << "[" << message << "]" << std::endl;
        kitchen << send;
        exit(0);
    } else {
        //reception << my_message;
        std::cout << "From kitchen " << "[" << *reception << "]" << std::endl;
    }
}