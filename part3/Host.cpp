#include "Host.h"
#include "Manager.h"
#include "Coffee.h"
#include "Food.h"
#include "Snack.h"
#include "Sandwich.h"
#include "Tea.h"

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

    // Create a new patron
    auto patron = std::make_shared<Patron>(name);
    manager->addPatron(patron);

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
                takeOrder(patron);
                break;
            case 2:
                displayOrderHistory(patron);
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
    std::cout <<
    " _ __ ___   ___ _ __  _   _\n" 
    "| '_ ` _ \\ / _ \\ '_ \\| | | |\n"
    "| | | | | |  __/ | | | |_| |\n"
    "|_| |_| |_|\\___|_| |_|\\__,_|\n\n";

    std::cout << "1: Black Coffee\n";
    std::cout << "2: White Coffee\n";
    std::cout << "3: Tea\n";
    std::cout << "4: Snacks\n";
    std::cout << "5: Sandwiches\n\n";
    std::cout << "Please enter the number of the item you wish to order, or 0 to finish your order.\n";
}

void Host::displaySnacks() {
    std::cout << "Snack Options:\n\n";
    std::cout << "1: Chips\n";
    std::cout << "2: Cookies\n";
    std::cout << "3: Chocolates\n\n";
    std::cout << "Enter the number of your choice: ";
}

void Host::displayVegetables() {
    std::cout << "Choose your vegetable:\n\n";
    std::cout << "1: Lettuce\n";
    std::cout << "2: Tomato\n";
    std::cout << "3: Onion\n";
    std::cout << "4: Cucumber\n\n";
    std::cout << "Select a vegetable (1-4): ";
}

void Host::displayProtein() {
    std::cout << "Choose your protein:\n\n";
    std::cout << "1: Turkey\n";
    std::cout << "2: Chicken\n";
    std::cout << "3: Ham\n";
    std::cout << "4: Tofu\n\n";
    std::cout << "Select a protein (1-4): ";
}

void Host::displaySauce() {
    std::cout << "Choose your sauce:\n\n";
    std::cout << "1: Mayonnaise\n";
    std::cout << "2: Mustard\n";
    std::cout << "3: Ketchup\n";
    std::cout << "4: Ranch\n\n";
    std::cout << "Select a sauce (1-4): ";
}

void Host::displayType() {
    std::cout << "Choose your tea type:\n\n";
    std::cout << "1: Hot\n";
    std::cout << "2: Iced\n\n";
    std::cout << "Select your type (1-2): ";
}

void Host::displayBrew() {
    std::cout << "Choose your tea brew:\n\n";
    std::cout << "1: Black\n";
    std::cout << "2: Earl Grey\n";
    std::cout << "3: Osmanthus\n";
    std::cout << "4: Green\n";
    std::cout << "5: Jasmine\n\n";
    std::cout << "Select your type (1-5): ";
}

void Host::takeOrder(std::shared_ptr<Patron> patron) {

    std::cout << "\nWelcome to Cafe++! Here is our menu:\n";

    std::shared_ptr<Order> order = std::make_shared<Order>();
    order->setPatron(patron); 

    bool ordering = true;
    int sugar; // later extd to size, other characteristics
    int snackChoice;
    int teaChoice;
    int sandwichChoice;
    std::string sandwichDescription = "Custom Sandwich";
    std::string teaDescription = "Tea";

    while (ordering) {
        displayMenu();
        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter sugar amount: ";
                std::cin >> sugar;
                order->addItem(std::make_shared<BlackCoffee>(sugar));
                std::cout << "Added Black Coffee with " << sugar << " blocks of sugar.\n";
                break;
            case 2:
                std::cout << "Enter sugar amount: ";
                std::cin >> sugar;
                order->addItem(std::make_shared<WhiteCoffee>(sugar));
                std::cout << "Added White Coffee with " << sugar << " blocks of sugar.\n";
                break;
            case 3:
                displayType();
                std::cin >> teaChoice;
                TeaType teaType;
                switch (teaChoice) {
                    case 1:
                        teaType = TeaType::Hot;
                        break;
                    case 2:
                        teaType = TeaType::Iced;
                        break;
                    default:
                        std::cout << "Invalid tea type choice. Please try again." << std::endl;
                        continue;  
                }

                displayBrew();
                std::cin >> teaChoice;
                TeaBrew brewChoice;
                switch(teaChoice) {
                    case 1:
                        brewChoice = TeaBrew::Black;
                        break;
                    case 2:
                        brewChoice = TeaBrew::EarlGrey;
                        break;
                    case 3:
                        brewChoice = TeaBrew::Osmanthus;
                        break;
                    case 4:
                        brewChoice = TeaBrew::Green;
                        break;
                    case 5:
                        brewChoice = TeaBrew::Jasmine;
                        break;
                    default:
                        std::cout << "Invalid tea brew choice. Please try again." << std::endl;
                        continue;
                }
                order->addItem(std::make_shared<Tea>(teaDescription, teaType, brewChoice));
                std::cout << "Added Custom Tea.\n";
                break;
            case 4:
                displaySnacks();
                std::cin >> snackChoice;
                switch (snackChoice) {
                    case 1:
                        order->addItem(std::make_shared<Snack>("Chips", SnackType::Chips));
                        std::cout << "Added Chips. \n";
                        break;
                    case 2:
                        order->addItem(std::make_shared<Snack>("Cookies", SnackType::Cookies));
                        std::cout << "Added Cookies. \n";
                        break;
                    case 3:
                        order->addItem(std::make_shared<Snack>("Chocolates", SnackType::Chocolates));
                        std::cout << "Added Chocolates. \n";
                        break;
                    default:
                        std::cout << "Invalid snack choice. Please try again." << std::endl;
                        continue;
                }
                break;
            case 5:
                std::cout << "Customize your sandwich:\n";
                displayVegetables();
                std::cin >> sandwichChoice;
                Vegetables vegChoice;
                switch (sandwichChoice) {
                    case 1:
                        vegChoice = Vegetables::Lettuce;
                        break;
                    case 2:
                        vegChoice = Vegetables::Tomato;
                        break;
                    case 3:
                        vegChoice = Vegetables::Onion;
                        break;
                    case 4:
                        vegChoice = Vegetables::Cucumber;
                        break;
                    default:
                        std::cout << "Invalid vegetable choice. Please try again." << std::endl;
                        continue;
                }

                displayProtein();
                std::cin >> sandwichChoice;
                Protein proteinChoice;
                switch (sandwichChoice) {
                    case 1:
                        proteinChoice = Protein::Turkey;
                        break;
                    case 2:
                        proteinChoice = Protein::Chicken;
                        break;
                    case 3:
                        proteinChoice = Protein::Ham;
                        break;
                    case 4:
                        proteinChoice = Protein::Tofu;
                        break;
                    default:
                        std::cout << "Invalid protein choice. Please try again." << std::endl;
                        continue;
                }

                displaySauce();
                std::cin >> sandwichChoice;
                Sauce sauceChoice;
                switch (sandwichChoice) {
                    case 1:
                        sauceChoice = Sauce::Mayonnaise;
                        break;
                    case 2:
                        sauceChoice = Sauce::Mustard;
                        break;
                    case 3:
                        sauceChoice = Sauce::Ketchup;
                        break;
                    case 4:
                        sauceChoice = Sauce::Ranch;
                        break;
                    default:
                        std::cout << "Invalid sauce choice. Please try again." << std::endl;
                        continue;
                }
            
                order->addItem(std::make_shared<Sandwich>(sandwichDescription, vegChoice, proteinChoice, sauceChoice));
                std::cout << "Added Custom Sandwich.\n";
                break;

            case 0:
                ordering = false;
                break;
            default:
                std::cout << "Invalid choice, please try again." << std::endl;
                displayMenu();
                continue;
        }
        if (choice != 0){
            std::cout << "\nWould you like to order something else?\n";
        }
    }

    if (!order->getItems().empty()) {
        manager->processOrder(patron->getName(), order);
    } else {
        std::cout << "No items ordered." << std::endl;
    }
}

void Host::displayOrderHistory(std::shared_ptr<Patron> patron) {
    const auto& history = patron->getOrderHistory();
    if (history.empty()) {
        std::cout << "No orders found for " << patron->getName() << " (ID: " << patron->getID() << ")." << std::endl;
    } else {
        std::cout << "Order history for " << patron->getName() << " (ID: " << patron->getID() << "):" << std::endl;
        for (const auto& order : history) {
            for (const auto& item : order.getItems()) {
                std::cout << item->getDescription() << "; ";
            }
            std::cout << std::endl; // New line after each order
        }
    }
}

void Host::notifyCompletion(const std::string& orderDetails,const std::string& patronName, const std::string& patronID) {
    std::cout << "Patron Name: " << patronName << " (ID: " << patronID << ")" << std::endl;

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