/*
** EPITECH PROJECT, 2021
** message.hpp
** File description:
** message.hpp
*/

#ifndef MESSAGE
#define MESSAGE

#include <sys/msg.h>
#include <sys/ipc.h>
#include <ostream>

namespace plz
{

    class Message
    {

        private:
            key_t m_key;
            int m_id;
            struct msg_buffer {
                long mesg_type;
                char *mesg_text;
            } m_message;
        public:
            Message(int proj_id);
            Message() = delete;
            ~Message() = default;
            void sendMessage(std::string& message);
            std::string readMessage();

    }; // class Message

} // namespace plz

void operator<<(plz::Message& obj, std::string& message);
std::string operator*(plz::Message &obj);

#endif //MESSAGE
