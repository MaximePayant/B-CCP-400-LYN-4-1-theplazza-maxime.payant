/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Reception
*/

#ifndef RECEPTION_HPP_
#define RECEPTION_HPP_

#include <vector>
#include <queue>

#include "plazza.hpp"
#include "communication/message.hpp"

namespace plz
{

    class Reception
    {

        private:
            std::vector<int> m_listStatusKitchen;
            std::vector<Message> m_messengerList;
            std::queue<Order> m_listOrder;
            unsigned int m_nbrKitchen;

        public:
            void checkStatusKitchen();
            void getStatus();
            int findKitchen();
            void sendOrder(unsigned kitchenTarget, plz::PizzaType type);
            int takeOrder(Order listOrder);
            int createKitchen();

            Reception();
            ~Reception() = default;

    }; // class Reception

} // namespace plz

#endif /* !RECEPTION_HPP_ */
