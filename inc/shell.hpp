/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** shell
*/

#ifndef SHELL_HPP_
#define SHELL_HPP_

#include <queue>
#include <fstream>

#include "plazza.hpp"
#include "reception.hpp"

namespace plz
{

    class Shell
    {

        private:
            std::string takeCommand() const;
            plz::Order verifyCommand(std::string& command);

        public:
            static float cookerMultiplier;
            static unsigned cooksNumber;
            static unsigned refillTime;
            static std::ofstream fileStream;

            Shell(float cookerMultiplier, unsigned cooksNumber, unsigned refillTime);
            ~Shell() = default;

            void exec();

    }; // class Shell

} // namespace plz

#endif /* !SHELL_HPP_ */
