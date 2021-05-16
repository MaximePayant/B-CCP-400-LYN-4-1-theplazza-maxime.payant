/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Cooker.hpp
*/

#ifndef __COOKER_H__
#define __COOKER_H__

#include <thread>

#include "chrono/Chrono.hpp"
#include "interfaces/ICooker.hpp"
#include "interfaces/IKitchen.hpp"

namespace plz
{

    class Cooker :
        public ICooker
    {

        private:
            IKitchen& m_kitchen;
            std::jthread m_thread;
            plz::PizzaType m_order;
            plz::Chrono m_timer;
            enum statut { Cooking, HasNothing } m_statut;

            void workHard() override;

        public:
            Cooker() = delete;
            Cooker(IKitchen& kitchen);
            ~Cooker() override;

    }; // class Cooker

} // namespace plz

#endif // __COOKER_H__