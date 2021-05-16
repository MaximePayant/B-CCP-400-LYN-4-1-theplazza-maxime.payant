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
#include <unordered_map>
#include <condition_variable>
#include <mutex>

#include "interfaces/IKitchen.hpp"
#include "interfaces/ICooker.hpp"
#include "communication/message.hpp"
#include "chrono/Chrono.hpp"

namespace plz
{
    class Kitchen :
        public IKitchen
    {

        private:
            const unsigned m_id;
            Message m_messenger;
            const unsigned m_cookerCount;
            unsigned m_pizzaWaiting;
            unsigned m_pizzaCooking;
            std::mutex m_mutex;
            std::queue<PizzaType> m_pizzaQueue;
            std::vector<std::unique_ptr<ICooker>> m_cookerList;
            std::unordered_map<plz::Ingredient, unsigned> m_ingredientStock;
            plz::Chrono m_serviceTimer;
            plz::Chrono m_deliveryTimer;
            bool m_isWorking;
            unsigned m_pizzaCooked;

            unsigned getFreePlace() const override;
            std::string getStatus() const;

        public:
            Kitchen() = delete;
            Kitchen(unsigned id);
            ~Kitchen() override;

            bool cookPizza(PizzaType pizza) override;
            void checkOrder(const std::string& message);
            PizzaType getNextOrder() override;
            bool gatherIngredient(plz::PizzaType type) override;
            void finishPizza(PizzaType type) override;

            void operator()();

    }; // class Kitchen

} // namespace plz

#endif // __KITCHEN_H__