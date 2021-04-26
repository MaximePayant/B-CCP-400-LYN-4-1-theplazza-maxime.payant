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
            char *m_text;

        public:
            Kitchen() = delete;
            Kitchen(Kitchen&&) = delete;
            Kitchen(const Kitchen&) = delete;
            Kitchen(char *message) : m_text(message) {}
            ~Kitchen() = default;

            const char *what() const throw()
            { return (m_text); }

    }; // class Kitchen

} // namespace plz

#endif // __PLAZZA_ERROR_KITCHEN_HPP__