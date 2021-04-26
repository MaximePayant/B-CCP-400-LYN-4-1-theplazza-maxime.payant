/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** main
*/

#include "shell.hpp"

int main(int ac, char **av)
{
    plz::Shell *shell = NULL;
    try {
        shell = new plz::Shell(std::stof(av[1]), std::stoi(av[2]), std::stoi(av[3]));
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