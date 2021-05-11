/*
** EPITECH PROJECT, 2021
** Communication.hpp
** File description:
** Communication.hpp
*/

#ifndef COMMUNICATION
#define COMMUNICATION

#include <iostream>
#include <exception>

namespace plz::error {
    class Communication : public std::exception
    {

        private:
            std::string m_message;

        public:
            explicit Communication(const char *message)
                : m_message(message) {}
            explicit Communication(const std::string& message)
                : m_message(message) {}
            ~Communication() noexcept {};

            const char *what() const noexcept
            { return (m_message.c_str()); }
    };
}

#endif //COMMUNICATION
