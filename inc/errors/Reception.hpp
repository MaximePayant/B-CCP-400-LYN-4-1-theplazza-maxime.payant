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
            std::string m_message;

        public:
            explicit Reception(const char *message)
                : m_message(message) {}
            explicit Reception(const std::string& message)
                : m_message(message) {}
            ~Reception() noexcept {};

            const char *what() const noexcept
            { return (m_message.c_str()); }

    }; // class Reception

} // namespace plz

#endif // __PLAZZA_ERROR_RECEPTION_HPP__