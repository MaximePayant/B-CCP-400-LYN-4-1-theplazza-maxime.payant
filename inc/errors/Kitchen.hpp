/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Kitchen.hpp
*/

#ifndef __PLAZZA_ERROR_KITCHEN_HPP__
#define __PLAZZA_ERROR_KITCHEN_HPP__

#include <iostream>
#include <exception>

namespace plz::error
{

    class Kitchen :
        public std::exception
    {

        private:
            std::string m_message;

        public:
            explicit Kitchen(const char *message)
                : m_message(message) {}
            explicit Kitchen(const std::string& message)
                : m_message(message) {}
            ~Kitchen() noexcept {};

            const char *what() const noexcept
            { return (m_message.c_str()); }

    }; // class Kitchen

} // namespace plz

#endif // __PLAZZA_ERROR_KITCHEN_HPP__