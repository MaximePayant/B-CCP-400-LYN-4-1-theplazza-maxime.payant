/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** message.inl
*/

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

inline std::string operator*(plz::Message &obj)
{
    return (obj.readMessage());
}