/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Cooker.hpp
*/

#ifndef __PLAZZA_ERROR_COOKER_HPP__
#define __PLAZZA_ERROR_COOKER_HPP__

#include <iostream>
#include <exception>

namespace plz::error
{

    class Cooker :
        public std::exception
    {

        private:
            std::string m_message;

        public:
            explicit Cooker(const char *message)
                : m_message(message) {}
            explicit Cooker(const std::string& message)
                : m_message(message) {}
            ~Cooker() noexcept {};

            const char *what() const noexcept
            { return (m_message.c_str()); }

    }; // class Cooker

} // namespace plz

#endif // __PLAZZA_ERROR_COOKER_HPP__