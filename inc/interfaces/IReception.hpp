/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** IReception.hpp
*/

#ifndef __IRECEPTION_H__
#define __IRECEPTION_H__

#include "plazza.hpp"

namespace plz
{

    class IReception
    {

        private:
            virtual void createKitchen() = 0;

        public:
            virtual ~IReception() = default;

            virtual void orderPizza(Order order) = 0;

    }; // class IReception

} // namespace plz

#endif // __IRECEPTION_H__