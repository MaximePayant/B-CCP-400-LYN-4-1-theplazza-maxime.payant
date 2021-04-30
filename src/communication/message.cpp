/*
** EPITECH PROJECT, 2021
** message.cpp
** File description:
** message.cpp
*/

#include <unistd.h>
#include <iostream>
#include "communication/message.hpp"

Message::Message() :
m_key(-1),
m_id(-1),
m_message()
{}

void Message::initServer()
{
    m_key = ftok("comFile", 65);
    m_id = msgget(m_key, 0666 | IPC_CREAT);
    m_message.mesg_type = 1;
}

void Message::initClient()
{
    m_key = ftok("comFile", 65);
    m_id = msgget(m_key, 0666 | IPC_CREAT);
    m_message.mesg_type = 1;
}

void Message::sendMessage(std::string& msg)
{
    char *buffer = msg.data();

    m_message.mesg_text = buffer;
    msgsnd(m_id, &m_message, sizeof(m_message), 0);
}

std::string Message::readMessage()
{
    std::string buffer;
    
    msgrcv(m_id, &m_message, sizeof(m_message), 1, 0);
    buffer = m_message.mesg_text;
    msgctl(m_id, IPC_RMID, nullptr);
    return (buffer);
}

void operator<<(Message& obj, std::string& message)
{
    obj.sendMessage(message);
}

std::string operator*(Message& obj)
{
    return (obj.readMessage());
}