#include "Host.h"
#include "Manager.h"
#include <iostream>

int main() {
    auto manager = std::make_shared<Manager>();
    auto host = std::make_shared<Host>(manager);
    manager->setHost(host);

    std::cout << "Starting Cafe++ System...\n";
    std::cout <<
    "  ____       __   __             \n"
    " / ___|__ _ / _| /_/   _     _   \n"
    "| |   / _` | |_ / _ \\_| |_ _| |_ \n"
    "| |__| (_| |  _|  __/_   _|_   _|\n"
    " \\____\\__,_|_| \\___|  |_|   |_|  \n";

    host->start();

    return 0;
}
