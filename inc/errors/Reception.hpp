/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Reception.hpp
*/

#ifndef __PLAZZA_ERROR_RECEPTION_HPP__
#define __PLAZZA_ERROR_RECEPTION_HPP__

#include <iostream>
#include <exception>

namespace plz::error
{

    class Reception :
        public std::exception
    {

        private:
            char *m_text;

        public:
            Reception() = delete;
            Reception(Reception&&) = delete;
            Reception(const Reception&) = delete;
            Reception(char *message) : m_text(message) {}
            ~Reception() = default;

            const char *what() const throw()
            { return (m_text); }

    }; // class Reception

} // namespace plz

#endif // __PLAZZA_ERROR_RECEPTION_HPP__