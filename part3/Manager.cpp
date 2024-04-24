#include "Manager.h"
#include "Host.h"

Manager::Manager() {
    // Constructor logic if any
}

void Manager::setHost(std::shared_ptr<Host> hst) {
    host = hst;
}

void Manager::processOrder(const std::string& patronName, const std::shared_ptr<Order>& order) {
    std::string orderDetails;

    // Send the order to the food maker and coffee maker
    foodMaker.processItem(order);
    coffeeMaker.processItem(order);
    teaMaker.processItem(order);
    
    for (auto& item : order->getItems()) {
        orderDetails += item->getDescription() + ", ";
    }

    // Remove the trailing comma and space if orderDetails is not empty
    if (!orderDetails.empty()) {
        orderDetails.pop_back();  // Remove the last space
        orderDetails.pop_back();  // Remove the last comma
    }

    // Notify the host when the entire order is prepared
    if (host) {
        auto [patronName, patronID] = getPatronNameAndID(order);
        host->notifyCompletion(orderDetails, patronName, patronID);
    }

    // Retrieve the linked patron and place the order in their history
    auto patron = order->getPatron();
    if (patron) {
        patron->placeOrder(*order);
    } else {
        std::cerr << "No patron linked to the order." << std::endl;
    }
}

void Manager::addPatron(const std::shared_ptr<Patron>& patron) {
    patrons.push_back(patron);
}

std::shared_ptr<Patron> Manager::getPatron(const std::string& name) {
    for (auto& patron : patrons) {
        if (patron->getName() == name) return patron;
    }
    return nullptr; // Return nullptr if no patron found
}

std::pair<std::string, std::string> Manager::getPatronNameAndID(const std::shared_ptr<Order>& order) {
    auto patron = order->getPatron();
    if (patron) {
        return {patron->getName(), patron->getID()};
    }
    return {"", ""}; // Return empty strings if patron is not found
}


// // Manager.cpp
// #include "Manager.h"
// #include <iostream>

// // -- below i got from chatgpt, which i think makes more sense in terms of what the manager class should do
// // Manager::Manager(Host* host) : host(host) {}

// // void Manager::processOrder(const Order& order) {
// //     // Assuming Order class has methods to check for food and drink items
// //     if (order.hasFoodItems()) {
// //         foodMaker.prepareFood(order.getFoodItems());
// //     }
// //     if (order.hasCoffeeItems()) {
// //         coffeeMaker.prepareCoffee(order.getCoffeeItems());
// //     }
// //     // Simulating preparation time or callback for demonstration
// //     notifyOrderComplete();
// // }

// // void Manager::notifyOrderComplete() {
// //     // Notify the Host that the order is ready
// //     if (host) {
// //         host->orderReady();
// //     }
// // }

// // ... but since we want to follow the uml:

// bool Manager::checkItemType(const Item& item) {
//     return item.getItemType() == ItemType::Food || item.getItemType() == ItemType::Drink;
// }

// void Manager::receiveOrderFromHost(const Order& order) {
//     orderQueue.push(order);
// }

// void Manager::assignOrder(const Order& order) {
//     // not sure how to implement
// }

// void Manager::updateOrderStatus(Order& order, const std::string& status) {
//     order.setOrderStatus(status);
// }