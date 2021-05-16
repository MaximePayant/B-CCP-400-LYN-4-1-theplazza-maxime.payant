/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** plazza
*/

#ifndef PLAZZA_HPP_
#define PLAZZA_HPP_

#include "types/Ingredient.hpp"
#include "types/PizzaType.hpp"
#include "types/PizzaSize.hpp"
#include "types/maps.hpp"
#include "types/Order.hpp"

#define MSG_RECEPTION 1
#define MSG_KITCHEN 2

namespace plz
{
    std::string getTime();
    void writeLog(const std::string& message);
}

#endif /* !PLAZZA_HPP_ */
