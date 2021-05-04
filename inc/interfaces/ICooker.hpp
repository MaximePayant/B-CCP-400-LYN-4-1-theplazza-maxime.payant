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

            virtual void startCooking(PizzaType pizza) = 0;
            virtual bool hasNothing() = 0;
            virtual bool canCook() = 0;

    }; // class ICooker

} // namespace plz

#endif // __ICOOKER_H__