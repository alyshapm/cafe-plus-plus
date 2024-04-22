// Manager.cpp
#include "Manager.h"
#include <iostream>

// -- below i got from chatgpt, which i think makes more sense in terms of what the manager class should do
// Manager::Manager(Host* host) : host(host) {}

// void Manager::processOrder(const Order& order) {
//     // Assuming Order class has methods to check for food and drink items
//     if (order.hasFoodItems()) {
//         foodMaker.prepareFood(order.getFoodItems());
//     }
//     if (order.hasCoffeeItems()) {
//         coffeeMaker.prepareCoffee(order.getCoffeeItems());
//     }
//     // Simulating preparation time or callback for demonstration
//     notifyOrderComplete();
// }

// void Manager::notifyOrderComplete() {
//     // Notify the Host that the order is ready
//     if (host) {
//         host->orderReady();
//     }
// }

// ... but since we want to follow the uml:

bool Manager::checkItemType(const Item& item) {
    return item.getItemType() == ItemType::Food || item.getItemType() == ItemType::Drink;
}

void Manager::receiveOrderFromHost(const Order& order) {
    orderQueue.push(order);
}

void Manager::assignOrder(const Order& order) {
    // not sure how to implement
}

void Manager::updateOrderStatus(Order& order, const std::string& status) {
    order.setOrderStatus(status);
}