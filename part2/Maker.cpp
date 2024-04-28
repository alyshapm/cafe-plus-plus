#include "Maker.h"
#include "Item.h"
#include <iostream>
#include <chrono>
#include <thread>

void Maker::processItem(const std::shared_ptr<Order>& order) {
    for (auto& item : order->getItems()) {
        if (dynamic_cast<Item*>(item.get())) {
            std::cout << "Preparing Item: " << item->getDescription() << std::endl;
        }
    }
}
