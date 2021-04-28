/*
** EPITECH PROJECT, 2021
** message.hpp
** File description:
** message.hpp
*/

#ifndef MESSAGE
#define MESSAGE

#include <sys/socket.h>
#include <ostream>
#include <netinet/in.h>

class Message
{
private:
    int m_socket;
    struct sockaddr_in m_addr;
    int m_kitchen;
public:
    Message();
    ~Message() = default;
    void sendMessage(std::string message) const;
    std::string readMessage();
    void connectToKitchen();
    void connectToReception();
    void initServer();
    void initClient(int port);
    [[nodiscard]] int getServerPort() const;
};

void operator<<(Message& obj, std::string message);
std::string operator*(Message &obj);

#endif //MESSAGE
