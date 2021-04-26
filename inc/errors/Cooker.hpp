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
            char *m_text;

        public:
            Cooker() = delete;
            Cooker(Cooker&&) = delete;
            Cooker(const Cooker&) = delete;
            Cooker(char *message) : m_text(message) {}
            ~Cooker() = default;

            const char *what() const throw()
            { return (m_text); }

    }; // class Cooker

} // namespace plz

#endif // __PLAZZA_ERROR_COOKER_HPP__