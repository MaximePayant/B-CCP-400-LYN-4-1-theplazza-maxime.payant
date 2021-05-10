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

#include "Kitchen.hpp"
#include "chrono/Chrono.hpp"

int main(int ac, char **av)
{
    (void)ac;
//    (void)av;
/*
    plz::Kitchen kitchen(10);
    plz::Chrono timer;

    for (int ctr = 0; ctr < 20;) {
        kitchen.cookPizza(plz::PizzaType::Americana);
        ctr += 1;
    }
    kitchen();
*/
    
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