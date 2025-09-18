#include <iostream>
#include "config_reader.h"

int main() {
    ConfigReader reader("test.ini");

    reader.setSection("database");
    std::cout << "[database] host: " << reader.readStr("host") << std::endl;
    std::cout << "[database] port: " << reader.readInt("port") << std::endl;
    std::cout << "[database] user: " << reader.readStr("user") << std::endl;
    std::cout << "[database] password: " << reader.readStr("password") << std::endl;

    reader.setSection("server");
    std::cout << "[server] ip: " << reader.readStr("ip") << std::endl;
    std::cout << "[server] port: " << reader.readInt("port") << std::endl;

    std::cout << "[server] not_exist: " << reader.readStr("not_exist") << std::endl;
    std::cout << "[server] not_exist int: " << reader.readInt("not_exist") << std::endl;

    return 0;
}