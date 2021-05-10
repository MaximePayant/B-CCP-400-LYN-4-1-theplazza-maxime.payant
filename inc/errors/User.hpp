/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** User.hpp
*/

#ifndef __PLAZZA_ERROR_USER_HPP__
#define __PLAZZA_ERROR_USER_HPP__

#include <iostream>
#include <exception>

namespace plz::error
{

    class User :
        public std::exception
    {

        private:
            std::string m_message;

        public:
            explicit User(const char *message)
                : m_message(message) {}
            explicit User(const std::string& message)
                : m_message(message) {}
            ~User() noexcept {};

            const char *what() const noexcept
            { return (m_message.c_str()); }

    }; // class User

} // namespace plz

#endif // __PLAZZA_ERROR_USER_HPP__