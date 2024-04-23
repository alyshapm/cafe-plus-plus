#include "Host.h"
#include "Manager.h"
#include "Coffee.h"
#include "Food.h"

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <iomanip>

Host::Host(std::shared_ptr<Manager> mgr) : manager(mgr) {}

void Host::start() {
    std::cout << "\nEnter patron name: ";
    std::string name;
    std::cin >> name;

    int choice = 0;
    do {
        std::cout << "\nChoose option:\n";
        std::cout << "1: Place Order\n";
        std::cout << "2: View Order History\n";
        std::cout << "3: Exit\n";
        std::cout << "Your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                takeOrder(name);
                break;
            case 2:
                displayOrderHistory(name);
                break;
            case 3:
                std::cout << "\nGoodbye, see you soon!" << std::endl;
                break;
            default:
                std::cout << "Invalid option selected, please try again." << std::endl;
                break;
        }
    } while (choice != 3);
}

void Host::displayMenu() {
    std::cout << "\nWelcome to Café++! Here is our menu:\n";
    std::cout << "1: Black Coffee\n";
    std::cout << "2: White Coffee\n";
    std::cout << "3: Snacks\n";
    std::cout << "Please enter the number of the item you wish to order, or 0 to finish your order.\n";
}

void Host::takeOrder(const std::string& patronName) {
    auto patron = manager->getPatron(patronName);
    if (!patron) {
        patron = std::make_shared<Patron>(patronName);
        manager->addPatron(patron);
    }

    displayMenu();

    std::shared_ptr<Order> order = std::make_shared<Order>();
    order->setPatron(patron); 

    bool ordering = true;
    int sugar; // later extd to size, other characteristics
    std::string foodChoice;

    while (ordering) {
        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter sugar amount: ";
                std::cin >> sugar;
                order->addItem(std::make_shared<BlackCoffee>(sugar));
                break;
            case 2:
                std::cout << "Enter sugar amount: ";
                std::cin >> sugar;
                order->addItem(std::make_shared<WhiteCoffee>(sugar));
                break;
            case 3:
                std::cout << "Enter type of snack (e.g., chips): ";
                std::cin >> foodChoice;
                order->addItem(std::make_shared<Snack>(foodChoice));
                break;
            case 0:
                ordering = false;
                break;
            default:
                std::cout << "Invalid choice, please try again." << std::endl;
                displayMenu();
                continue;
        }
    }

    if (!order->getItems().empty()) {
        manager->processOrder(patronName, order);
    } else {
        std::cout << "No items ordered." << std::endl;
    }
}

void Host::displayOrderHistory(const std::string& patronName) {
    auto patron = manager->getPatron(patronName);
    if (!patron) {
        std::cout << "No such patron found." << std::endl;
        return;
    }

    const auto& history = patron->getOrderHistory();
    if (history.empty()) {
        std::cout << "No orders found for " << patronName << "." << std::endl;
    } else {
        std::cout << "Order history for " << patronName << ":" << std::endl;
        for (const auto& order : history) {
            for (const auto& item : order.getItems()) {
                std::cout << item->getDescription() << "; ";
            }
            std::cout << std::endl; // New line after each order
        }
    }
}

void Host::notifyCompletion(const std::string& orderDetails) {
    std::stringstream ss(orderDetails);
    std::string item;
    std::string header = "Order Complete! Receipt:";
    std::vector<std::string> items;

    // Extract each item, trim them inline, and store them
    while (getline(ss, item, ',')) {
        item.erase(item.begin(), std::find_if(item.begin(), item.end(), [](unsigned char ch) {
            return !std::isspace(ch);
        }));
        item.erase(std::find_if(item.rbegin(), item.rend(), [](unsigned char ch) {
            return !std::isspace(ch);
        }).base(), item.end());

        items.push_back(item);
    }

    // Determine the longest line for formatting
    size_t maxContentLength = header.length();
    for (const auto& line : items) {
        if (line.length() > maxContentLength) {
            maxContentLength = line.length();
        }
    }

    // Create borders based on the longest line
    int padLength = maxContentLength + 4;
    std::string topBottomBorder = "+" + std::string(padLength, '-') + "+";

    // Output the formatted receipt
    std::cout << std::endl << topBottomBorder << std::endl;
    std::cout << "| " << std::setw(padLength) << std::left << header << " |" << std::endl;
    for (const auto& line : items) {
        std::cout << "| " << std::setw(padLength) << std::left << line << " |" << std::endl;
    }
    std::cout << topBottomBorder << std::endl;
}

// void Host::notifyCompletion(const std::string& orderDetails) {
//     std::cout << "Order completed: " << orderDetails << std::endl;
// }

// #include "Host.h"
// #include <iostream>

// void Host::processOrder(const Order& order) {
//     // add logic, it would be something like the following:
//     // Order order;
//     // std::string name, item;
//     // std::cout << "Enter your name: ";
//     // std::cin >> name;
//     // std::cout << "What would you like to order? (Enter 'done' to finish): ";
//     // while (std::cin >> item && item != "done") {
//     //     order.addItem(item);
//     // }
//     // manager.processOrder(order);
    
//     std::cout << "Processing order ID: " << order.getOrderID() << std::endl; // placeholder
// }

// void Host::displayMenu(const Item& item) {
//     std::cout << "Menu item: " << item.getItemName() << " - Price: " << item.getItemPrice() << std::endl;
// }

// void Host::displayOrderStatus(const Order& order) {
//     // Logic to display the order status
//     std::cout << "Order ID: " << order.getOrderID() << " - Status: " << order.getStatusAsString() << std::endl;
// }

// // to be updated in UML: call patron for completed order
// // void Host::callPatron(std::string name) {
// //     std::cout << name << ", your order is ready!" << std::endl;
// // }