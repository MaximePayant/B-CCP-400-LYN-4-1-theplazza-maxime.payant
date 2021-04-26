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
            char *m_text;

        public:
            User() = delete;
            User(User&&) = delete;
            User(const User&) = delete;
            User(char *message) : m_text(message) {}
            ~User() = default;

            const char *what() const throw()
            { return (m_text); }

    }; // class User

} // namespace plz

#endif // __PLAZZA_ERROR_USER_HPP__