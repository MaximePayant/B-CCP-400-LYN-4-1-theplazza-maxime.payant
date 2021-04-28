/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** shell
*/

#ifndef SHELL_HPP_
#define SHELL_HPP_
#include "plazza.hpp"

namespace plz {
    class Shell {
        private:
            std::string &takeCommand(std::string &command);
            bool verifyPizza(const std::string &name);
            Order verifyCommand(std::string &command);
            std::vector<Order> listOrder;
        public:
            const float cookerMultiplier;
            const unsigned cooksNumber;
            const unsigned refillTime;
            unsigned int exec();
            Shell(float cookerMultiplier, unsigned cooksNumber, unsigned refillTime);
            ~Shell();
    };
}

#endif /* !SHELL_HPP_ */
