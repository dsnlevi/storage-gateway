#include <iostream>
#include <string>
#include "server.hpp"
#include "../log/log.h"

int main(int argc, char* argv[])
{
    if (argc != 4)
    {
        std::cerr << "Usage:journal_server <address> <port> <file>";
        return 1;
    }
    //todo read from config file
    uint32_t io_service_pool_size = 1;
    std::remove(argv[3]);
    DRLog::log_init("journal_server.log");
    try
    {
        Journal::Server server(argv[1], argv[2], argv[3], io_service_pool_size);
        server.run();
    }
    catch (std::exception& e)
    {
        std::cerr <<"exception:" << e.what() << "\n";
    }

    return 0;
}
