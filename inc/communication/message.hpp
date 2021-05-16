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

    struct msg_buffer {
        long mesg_type;
        char mesg_text[500];
    };

    class Message
    {

        private:
            int m_key;
            int m_id;
            int m_Stype;
            int m_Rtype;

        public:
            Message(int proj_id, int send_type, int rec_type);
            Message() = delete;
            ~Message();
            void sendMessage(std::string& message);
            std::string readMessage();

        friend void operator<<(std::ostream& os, Message& obj);

    }; // class Message

    inline void operator<<(std::ostream& os, Message& obj)
    {
        os << "Key: " << obj.m_key << std::endl
           << "Id: " << obj.m_id << std::endl
           << "Stype: " << obj.m_Stype << std::endl
           << "Rtype: " << obj.m_Rtype << std::endl;
    }

    inline void operator<<(plz::Message& obj, std::string& message)
    {
        obj.sendMessage(message);
    }

    inline void operator>>(plz::Message& obj, std::string& message)
    {
        message = obj.readMessage();
    }

} // namespace plz

std::string operator*(plz::Message &obj);

#endif //MESSAGE
