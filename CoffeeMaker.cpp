#include "CoffeeMaker.h"
#include "Coffee.h" 
#include <iostream>
#include <chrono>
#include <thread>

void CoffeeMaker::prepareCoffee(const std::shared_ptr<Order>& order) {
    for (auto& item : order->getItems()) {
        if (dynamic_cast<Coffee*>(item.get())) {
            std::cout << "Brewing coffee: " << item->getDescription() << std::endl;

            // ASCII art for the coffee cup
            const char* coffeeCup[] = {
                "        ( (",
                "         ) )",
                "      .........",
                "      |       |___",
                "      |       |_  |",
                "      |  :-)  |_| |",
                "      |       |___|",
                "      |_______|"
            };

            // Print each line with a delay
            for (auto line : coffeeCup) {
                std::cout << line << std::endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Delay for 500 milliseconds
            }
        }
    }
}