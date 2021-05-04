/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Kitchen.hpp
*/

#ifndef __KITCHEN_H__
#define __KITCHEN_H__

#include <vector>
#include <queue>
#include <memory>

#include "interfaces/IKitchen.hpp"
#include "interfaces/ICooker.hpp"

namespace plz
{
    class Kitchen :
        public IKitchen
    {

        private:
            const unsigned m_cookerCount;
            unsigned m_pizzaCount;
            std::queue<PizzaType> m_pizzaStack;
            std::vector<std::unique_ptr<ICooker>> m_cookerList;

        public:
            Kitchen() = delete;
            Kitchen(int cookerCount);
            ~Kitchen();

            void cookPizza(PizzaType pizza) override;
            unsigned getFreePlace() override;

    }; // class Kitchen

} // namespace plz

#endif // __KITCHEN_H__