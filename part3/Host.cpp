#include "Host.h"
#include "Manager.h"
#include "Coffee.h"
#include "Food.h"
#include "Snack.h"
#include "Sandwich.h"
#include "Tea.h"
#include "Util.h"
#include "WhiteCoffee.h"

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
    std::cout << "Enter 0 for none or to go to the next step.\n";
    std::cout << "Select a vegetable (1-4): ";
}

void Host::displayProtein() {
    std::cout << "Choose your protein:\n\n";
    std::cout << "1: Turkey\n";
    std::cout << "2: Chicken\n";
    std::cout << "3: Ham\n";
    std::cout << "4: Tofu\n\n";
    std::cout << "Enter 0 for none or to go to the next step.\n";
    std::cout << "Select a protein (1-4): ";
}

void Host::displaySauce() {
    std::cout << "Choose your sauce:\n\n";
    std::cout << "1: Mayonnaise\n";
    std::cout << "2: Mustard\n";
    std::cout << "3: Ketchup\n";
    std::cout << "4: Ranch\n\n";
    std::cout << "Press 0 for none or to go to the next step.\n";
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

void Host::displayMilk() {
    std::cout << "Choose your milk:\n\n";
    std::cout << "1: Regular\n";
    std::cout << "2: Almond\n";
    std::cout << "3: Soy\n";
    std::cout << "4: Oat\n";
    std::cout << "Select your type (1-4): ";
}

void Host::displayCoffeeType() {
    std::cout << "Choose your type:\n\n";
    std::cout << "1: Regular\n";
    std::cout << "2: Latte\n";
    std::cout << "3: Cappuccino\n";
    std::cout << "4: Flat White\n";
    std::cout << "Select your type (1-4): ";
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
    int milkChoice;
    int coffeeChoice;
    std::vector<VegetableChoice> vegChoices;
    std::vector<ProteinChoice> proteinChoices;
    std::vector<SauceChoice> sauceChoices;
    bool vegSelected = false;
    bool proteinSelected = false;
    bool sauceSelected = false;
    std::string sandwichDescription = "Custom Sandwich";
    std::string teaDescription = "Tea";
    std::string coffeeDescription = "White Coffee";

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
                displayCoffeeType();
                std::cin >> coffeeChoice;
                CoffeeType coffeeType;
                switch(coffeeChoice) {
                    case 1:
                        coffeeType = CoffeeType::Regular;
                        break;
                    case 2:
                        coffeeType = CoffeeType::Latte;
                        break;
                    case 3:
                        coffeeType = CoffeeType::Cappuccino;
                        break;
                    case 4:
                        coffeeType = CoffeeType::FlatWhite;
                        break;
                    default:
                        std::cout << "Invalid coffee type choice. Please try again." << std::endl;
                        continue;
                }

                displayMilk();
                std::cin >> coffeeChoice;
                MilkType milkType;
                switch(coffeeChoice) {
                    case 1:
                        milkType = MilkType::Regular;
                        break;
                    case 2:
                        milkType = MilkType::Almond;
                        break;
                    case 3:
                        milkType = MilkType::Soy;
                        break;
                    case 4:
                        milkType = MilkType::Oat;
                        break;
                    default:
                        std::cout << "Invalid milk type choice. Please try again." << std::endl;
                        continue;
                }
                std::cout << "Enter sugar amount: ";
                std::cin >> sugar;
                order->addItem(std::make_shared<WhiteCoffee>(coffeeType, milkType, sugar));
                std::cout << "Added Custom Coffee.\n";
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
                std::cout << "Enter sugar amount: "; 
                std::cin >> sugar;

                order->addItem(std::make_shared<Tea>(teaDescription, teaType, brewChoice, sugar));
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
                std::cout << "Create a custom sandwich in three steps!\n";
                std::cout << "Choose as many options for each step:\n";
                std::cout << "(At least one option from one of the steps has to be chosen)\n";

                // Clear previous choices
                vegChoices.clear();
                proteinChoices.clear();
                sauceChoices.clear();

                int vegChoice;
                do {
                    displayVegetables();
                    std::cin >> vegChoice;
                    if (vegChoice == 0) {
                        break; // Exit loop if choice is 0
                    } else if (vegChoice >= 1 && vegChoice <= 4) {
                        vegChoices.push_back(static_cast<VegetableChoice>(vegChoice - 1));
                    } else {
                        std::cout << "Invalid vegetable choice. Please try again." << std::endl;
                    }
                } while (true); // Continue looping until choice is 0

                int proteinChoice;
                do {
                    displayProtein();
                    std::cin >> proteinChoice;
                    if (proteinChoice == 0) {
                        break; // Exit loop if choice is 0
                    } else if (proteinChoice >= 1 && proteinChoice <= 4) {
                        proteinChoices.push_back(static_cast<ProteinChoice>(proteinChoice - 1));
                    } else {
                        std::cout << "Invalid protein choice. Please try again." << std::endl;
                    }
                } while (true); // Continue looping until choice is 0

                int sauceChoice;
                do {
                    displaySauce();
                    std::cin >> sauceChoice;
                    if (sauceChoice == 0) {
                        break; // Exit loop if choice is 0
                    } else if (sauceChoice >= 1 && sauceChoice <= 4) {
                        sauceChoices.push_back(static_cast<SauceChoice>(sauceChoice - 1));
                    } else {
                        std::cout << "Invalid sauce choice. Please try again." << std::endl;
                    }
                } while (true); // Continue looping until choice is 0

                // Add sandwich only if at least one ingredient is selected
                if (!vegChoices.empty() || !proteinChoices.empty() || !sauceChoices.empty()) {
                    order->addItem(std::make_shared<Sandwich>(sandwichDescription, vegChoices, proteinChoices, sauceChoices));
                    std::cout << "Added Custom Sandwich.\n";
                } else {
                    std::cout << "No ingredients selected for sandwich." << std::endl;
                }
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

    // Update order history in file
     std::string orderHistory = patronName + " " + patronID + " " + orderDetails;
     Util::writeToFile("order_history.txt", orderHistory);
}