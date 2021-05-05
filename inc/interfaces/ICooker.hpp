/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** ICooker.hpp
*/

#ifndef __ICOOKER_H__
#define __ICOOKER_H__

#include "plazza.hpp"

namespace plz
{

    class ICooker
    {

        public:
            virtual ~ICooker() = default;

            virtual bool isCooking() = 0;

    }; // class ICooker

} // namespace plz

#endif // __ICOOKER_H__