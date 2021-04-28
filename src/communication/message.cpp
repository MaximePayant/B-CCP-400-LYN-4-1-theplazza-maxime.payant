/*
** EPITECH PROJECT, 2021
** message.cpp
** File description:
** message.cpp
*/

#include <unistd.h>
#include <iostream>
#include "communication/message.hpp"

Message::Message() : m_socket(-1), m_addr(), m_kitchen(-1)
{}

void Message::initServer()
{
    socklen_t size = sizeof(m_addr);

    m_socket = socket(AF_INET, SOCK_STREAM, 0);
    m_addr.sin_family = AF_INET;
    m_addr.sin_port = htons(0);
    m_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    bind(m_socket, (struct sockaddr *)&m_addr, size);
    listen(m_socket, 5);
    getsockname(m_socket, (struct sockaddr *)&m_addr, &size);
}

int Message::getServerPort() const
{
    return (ntohs(m_addr.sin_port));
}

void Message::initClient(int port)
{
    m_kitchen = socket(AF_INET, SOCK_STREAM, 0);
    m_addr.sin_family = AF_INET;
    m_addr.sin_port = htons(port);
    m_addr.sin_addr.s_addr = htonl(INADDR_ANY);
}

void Message::connectToKitchen()
{
    socklen_t size = sizeof(m_addr);

    m_kitchen = accept(m_socket, (struct sockaddr *)&m_addr, &size);
}

void Message::connectToReception()
{
    socklen_t size = sizeof(m_addr);

    connect(m_kitchen, (struct sockaddr *)&m_addr, size);
}

void Message::sendMessage(std::string message) const
{
    dprintf(m_kitchen, "%s", message.c_str());
}

std::string Message::readMessage()
{
    char *buffer = new char[10];
    std::string result;

    while (read(m_kitchen, buffer, 10) > 0) {
        result += buffer;
        for (int i = 0; i < 10; i++)
            buffer[i] = '\0';
    }
    delete[] buffer;
    return (result);
}

void operator<<(Message& obj, std::string message)
{
    obj.sendMessage(message);
}

std::string operator*(Message& obj)
{
    return (obj.readMessage());
}