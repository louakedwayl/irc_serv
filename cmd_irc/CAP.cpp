#include "../data.hpp"

void CAP (Client* client)
{
    Data &data = Data::getInstance();
    client->appendToSendBuffer("CAP * LS :\r\n");

    for (size_t i = 0; i < data.getPollFds().size(); ++i)
    {
        if (data.getPollFds()[i].fd == client->getFd())
        {
            data.getPollFds()[i].events |= POLLOUT;
            break;
        }
    }
}