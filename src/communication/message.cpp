/*
** EPITECH PROJECT, 2021
** message.cpp
** File description:
** message.cpp
*/

#include <unistd.h>
#include <string.h>
#include <iostream>
#include "communication/message.hpp"
#include "errors/Communication.hpp"

plz::Message::Message(int proj_id, int send_type, int rec_type) :
m_key(-1),
m_id(-1),
m_Stype(send_type),
m_Rtype(rec_type)
{
    m_key = ftok("comFile", proj_id);
    m_id = msgget(m_key, 0666 | IPC_CREAT);
    if (m_key == -1 || m_id == -1)
        throw (plz::error::Communication("Message cannot been create!"));
}

plz::Message::~Message()
{
    msgctl(m_id, IPC_RMID, nullptr);
}

void plz::Message::sendMessage(std::string& msg)
{
    plz::msg_buffer message{m_Stype, ""};
    int result;

    strcpy(message.mesg_text, msg.c_str());
    result = msgsnd(m_id, &message, sizeof(message.mesg_text), 0);
    if (result == -1) {
        perror("msgsnd");
        throw (plz::error::Communication("Message cannot been send!"));
    }
}

std::string plz::Message::readMessage()
{
    plz::msg_buffer message{1, ""};
    std::string buffer;

    msgrcv(m_id, &message, sizeof(message.mesg_text), m_Rtype, IPC_NOWAIT);
    buffer = message.mesg_text;
    return (buffer);
}