/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** shell
*/

#include "shell.hpp"


plz::Shell::Shell(float cookerMultiplier, unsigned int cooksNumber, unsigned int refillTime) : cookerMultiplier(cookerMultiplier), cooksNumber(cooksNumber), refillTime(refillTime)
{
}

plz::Shell::~Shell()
{
}


std::string &plz::Shell::takeCommand(std::string &command)
{
    std::getline(std::cin, command);
    command.push_back(';');
    return command;
}

plz::Order plz::Shell::verifyCommand(std::string &command)
{
    Order order;
 
    std::regex words_regex("(\\s*?([a-zA-Z]+)\\s+(S|M|L|XL|XXL)\\s+x([1-9][0-9]*));");
    auto words_begin = std::sregex_iterator(command.begin(), command.end(), words_regex);
    auto words_end = std::sregex_iterator();
 
    if (std::distance(words_begin, words_end) == 0)
        throw "error with regex";
    
    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        std::smatch match = *i;
        std::string match_str = match.str();      
        
        //std::cout << (*i)[2] << std::endl;
        //std::cout << (*i)[3] << std::endl;
        //std::cout << (*i)[4] << std::endl;
        if ((*i)[2].compare("regina") == 0)
            order.type = Regina;
        else if ((*i)[2].compare("margarita") == 0)
            order.type = Margarita;
        else if ((*i)[2].compare("americana") == 0)
            order.type = Americana;
        else if ((*i)[2].compare("fantasia") == 0)
            order.type = Fantasia;
        else
            throw "nom de la pizza inconue";
        if ((*i)[3].compare("S") == 0)
            order.size = S;
        else if ((*i)[3].compare("M") == 0)
            order.size = M;
        else if ((*i)[3].compare("L") == 0)
            order.size = L;
        else if ((*i)[3].compare("XL") == 0)
            order.size = XL;
        else if ((*i)[3].compare("XXL") == 0)
            order.size = XXL;
        else
            throw "taille de la pizza inconue";
        order.count = std::stoi((*i)[4]);
        listOrder.push_back(order);
//        std::cout << "test " << order.count  << " " << order.size << " "  << order.type << std::endl;
    }
}

unsigned int plz::Shell::exec()
{
    std::string command;
    std::cout << "Welcum Welcum, bienvenue dans le restaurant \"la fine bouche\"\nnous vous proposons les meilleurs pizzas du pays\nfaites votre choix!\n\nPizza: regina, margarita, americana, fantasia.\nTaille: S, M, L, XL, XXL\n\n\"Mode d'emploie de commande:'nom de la pizza' 'taille' x'nombre de pizza'\"\nExample: \"regina XXL x2; fantasia M x3; margarita S x1\"" << std::endl;
    while (1) {
        std::cout << "\nPuis-je avoir votre commande ?\nChoix: ";
        try {
            verifyCommand(this->takeCommand(command));
        }
        catch (const char *msg) {
            std::cerr << msg << std::endl;
        }
    }
}