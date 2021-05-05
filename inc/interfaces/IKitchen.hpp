/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** IKitchen.hpp
*/

#ifndef __IKITCHEN_H__
#define __IKITCHEN_H__

#include "plazza.hpp"

namespace plz
{

    class IKitchen
    {

        public:
            virtual ~IKitchen() = default;

            virtual bool cookPizza(PizzaType pizza) = 0;
            virtual unsigned getFreePlace() = 0;
            virtual PizzaType getNextOrder() = 0;
            virtual bool nothingToCook() = 0;

    }; // class IKitchen

} // namespace plz

#endif // __IKITCHEN_H__