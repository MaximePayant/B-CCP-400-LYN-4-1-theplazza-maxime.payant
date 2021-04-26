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

            virtual void cookPizza(PizzaType pizza) = 0;
            virtual unsigned getFreeCookers() = 0;

    }; // class IKitchen

} // namespace plz

#endif // __IKITCHEN_H__