/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** main
*/

#include "plazza.hpp"

int main(int ac, char **av)
{
    plz::Shell *shell = NULL;
    try {

        shell = new plz::Shell(1, 1, 1);
        unsigned ret = shell->exec();
        delete (shell);
        return (ret);
    }
    catch (std::exception const &error){
        std::cerr << error.what() << std::endl;

        return (0);
    }
    return (0);
}