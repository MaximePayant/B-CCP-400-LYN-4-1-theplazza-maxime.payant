/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** shell
*/

#include <regex>

#include "shell.hpp"

float plz::Shell::cookerMultiplier = 0;
unsigned plz::Shell::cooksNumber = 0;
unsigned plz::Shell::refillTime = 0;
std::ofstream plz::Shell::fileStream(".plazzaLog");

plz::Shell::Shell(float cookerMultiplierVal, unsigned int cooksNumberVal, unsigned int refillTimeVal)
{
    cookerMultiplier = cookerMultiplierVal;
    cooksNumber = cooksNumberVal;
    refillTime = refillTimeVal;
}

std::string plz::Shell::takeCommand() const
{
    std::string command;

    std::getline(std::cin, command);
    command.push_back(';');
    return (command);
}

plz::Order plz::Shell::verifyCommand(std::string &command)
{
    plz::Order order;

    std::regex words_regex("(\\s*?([a-zA-Z]+)\\s+(S|M|L|XL|XXL)\\s+x([1-9][0-9]*));");
    auto words_begin = std::sregex_iterator(command.begin(), command.end(), words_regex);
    auto words_end = std::sregex_iterator();

    if (std::distance(words_begin, words_end) == 0)
        throw "error with regex";

    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        std::smatch match = *i;
        order.type << match[2];
        order.size << match[3];
        order.count = std::stoi(match[4]);
    }
    return (order);
}

void plz::Shell::exec()
{
    bool isWorking = true;
    plz::Reception reception;
    plz::Order order;
    std::string command;

    std::cout << "Wellcome Wellcome, bienvenue dans le restaurant \"la fine bouche\""   << std::endl
              << "nous vous proposons les meilleurs pizzas du pays"                     << std::endl
              << "faites votre choix!"                                                  << std::endl << std::endl
              << "Pizza: regina, margarita, americana, fantasia."                       << std::endl
              << "Taille: S, M, L, XL, XXL"                                             << std::endl << std::endl
              << "\"Comment commander :'nom de la pizza' 'taille' x'nombre de pizza'\"" << std::endl
              << "Example: \"regina XXL x2; fantasia M x3; margarita S x1\""            << std::endl;
    while (isWorking) {
        std::cout << "\nVous souhaiterez commander ?" << std::endl
                  << "Choix: ";
        try {
            command = takeCommand();
            if (command == "exit;")
                isWorking = false;
            else if (command == "status;")
                reception.getStatus();
            else {
                order = verifyCommand(command);
                reception.takeOrder(order);
                std::cout << std::endl;
            }
        }
        catch (const char *msg) {
            std::cerr << msg << std::endl;
        }
    }
}