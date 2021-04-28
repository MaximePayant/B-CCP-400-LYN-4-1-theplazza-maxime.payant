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

    reception.initServer();
    kitchen.initClient(reception.getServerPort());

    int pid = fork();
    if (pid == 0) {
        std::string message;

        kitchen.connectToReception();
        message = *kitchen;
        std::cout << "I got: " << "[" << message << "]" << std::endl;
        exit(0);
    } else {
        reception.connectToKitchen();
        reception << std::string("Hello World my name is V");
    }
}