/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Reception
*/

#ifndef RECEPTION_HPP_
#define RECEPTION_HPP_

#include "plazza.hpp"
#include "communication/message.hpp"

namespace plz
{

    class Reception
    {

        private:
            std::vector<int> m_listStatusKitchen;
            std::vector<Message> m_listReceptionMessage;
            std::vector<Message> m_listKitchenMessage;
            std::queue<Order> m_listOrder;
            unsigned int m_nbrKitchen;

        public:
            void checkStatusKitchen();
            int findKitchen();
            void sendOrder(int kitchenTarget, int type);
            std::queue<Order> deleteOrder(std::queue<Order> listOrder);
            int exec(std::queue<Order> listOrder);
            int recupMessageStatus(Message message);
            int createKitchen();

            Reception();
            ~Reception();

    }; // class Reception

} // namespace plz

#endif /* !RECEPTION_HPP_ */
