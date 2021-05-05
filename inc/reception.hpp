/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Reception
*/

#ifndef RECEPTION_HPP_
#define RECEPTION_HPP_
#include "plazza.hpp"

namespace plz {
    class Reception {
        private:
            std::vector<int> listStatusKitchen;
            std::queue<Order> listOrder;
            unsigned int nbrKitchen;
        public:
            std::vector<int> checkStatusKitchen();
            int findKitchen();
            void sendOrder(int kitchenTarget, int type);
            std::queue<Order> deleteOrder(std::queue<Order> listOrder);
            int exec(std::queue<Order> listOrder);
            Reception();
            ~Reception();
    };
}

#endif /* !RECEPTION_HPP_ */
