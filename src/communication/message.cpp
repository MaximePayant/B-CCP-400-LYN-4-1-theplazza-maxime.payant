/*
** EPITECH PROJECT, 2021
** message.cpp
** File description:
** message.cpp
*/

#include <unistd.h>
#include <iostream>
#include "communication/message.hpp"

plz::Message::Message(int proj_id) :
m_key(-1),
m_id(-1),
m_message()
{
    m_key = ftok("comFile", 60 + proj_id);
    m_id = msgget(m_key, 0666 | IPC_CREAT);
    m_message.mesg_type = 1;
}

void plz::Message::sendMessage(std::string& msg)
{
    m_message.mesg_text =  msg.data();
    msgsnd(m_id, &m_message, sizeof(m_message), 0);
}

std::string plz::Message::readMessage()
{
    std::string buffer;

    msgrcv(m_id, &m_message, sizeof(m_message), 1, 0);
    buffer = m_message.mesg_text;
    msgctl(m_id, IPC_RMID, nullptr);
    return (buffer);
}

void operator<<(plz::Message& obj, std::string& message)
{
    obj.sendMessage(message);
}

std::string operator*(plz::Message& obj)
{
    return (obj.readMessage());
}