/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** shell
*/

#ifndef SHELL_HPP_
#define SHELL_HPP_
#include "plazza.hpp"
#include "reception.hpp"
namespace plz {
    class Shell {
        private:
            std::string &takeCommand(std::string &command);
            bool verifyPizza(const std::string &name);
            void verifyCommand(std::string &command);
            std::queue<Order> listOrder;
        public:

            const float cookerMultiplier;
            const unsigned cooksNumber;
            const unsigned refillTime;
            unsigned int exec();
            unsigned int sendCommand(std::queue<Order> listOrder, plz::Reception *recep);
            Shell(float cookerMultiplier, unsigned cooksNumber, unsigned refillTime);
            ~Shell();
    };
}

#endif /* !SHELL_HPP_ */
