/*
** EPITECH PROJECT, 2021
** main.cpp
** File description:
** main.cpp
*/

#include <iostream>
#include <unistd.h>
#include "shell.hpp"
#include "communication/message.hpp"
#include "shell.hpp"

#include "Kitchen.hpp"
#include "chrono/Chrono.hpp"

int main(int ac, char **av)
{
    /*
    plz::Message reception_1(1);
    plz::Message kitchen_1(1);
    plz::Message reception_2(2);
    plz::Message kitchen_2(2);
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
    */

    (void)ac;

    try {
        plz::Shell shell(std::stof(av[1]), std::stoi(av[2]), std::stoi(av[3]));
        unsigned ret = shell.exec();
        return (ret);
    }
    catch (std::exception const &error){
        std::cerr << error.what() << std::endl;
        return (0);
    }

    //std::cout << "From kitchen " << "[" << *reception << "]" << std::endl;
    /*plz::Kitchen kitchen(10);
    plz::Chrono timer;

    for (int ctr = 0; ctr < 20;) {
        kitchen.cookPizza(plz::PizzaType::Americana);
        ctr += 1;
    }
    kitchen();*/

    /*
    plz::Shell *shell = NULL;
    try {
        shell = new plz::Shell(std::stof(av[1]), std::stoi(av[2]), std::stoi(av[3]));
        unsigned ret = shell->exec();
        delete (shell);
        return (ret);
    }
    catch (std::exception const &error){
        std::cerr << error.what() << std::endl;
        return (0);
    }
    */
}