#include "TeaMaker.h"
#include "Tea.h" 
#include <iostream>
#include <chrono>
#include <thread>

void TeaMaker::processItem(const std::shared_ptr<Order>& order) {
    for (auto& item : order->getItems()) {
        if (dynamic_cast<Tea*>(item.get())) {
            std::cout << "Brewing tea: " << item->getDescription() << std::endl;

            // ASCII art for the coffee cup
            const char* teaCup[] = {
            "                 ;,'",
            "        _o_    ;:;'",
            "    ,-.'---`.__ ;",
            "   ((j`=====',-'",
            "    `-\\    /",
            "       `---' ",
            };

            // Print each line with a delay
            for (auto line : teaCup) {
                std::cout << line << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Delay for 500 milliseconds
            }
        }
    }
}