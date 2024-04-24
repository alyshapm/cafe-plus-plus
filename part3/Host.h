#ifndef HOST_H
#define HOST_H

#include "Order.h"
#include "BlackCoffee.h"
#include "WhiteCoffee.h"
#include "Snack.h"
#include "Patron.h"
#include "Sandwich.h"
#include "Tea.h"

#include <iostream>
#include <memory>

class Manager;

class Host {
    std::shared_ptr<Manager> manager;
public:
    Host(std::shared_ptr<Manager> mgr);
    void start();
    void takeOrder(std::shared_ptr<Patron> patron);
    void notifyCompletion(const std::string& orderDetails, const std::string& patronName, const std::string& patronID);
    void displayOrderHistory(std::shared_ptr<Patron> patron);
    void displayMenu();
    void displaySnacks();
    void displayVegetables();
    void displayProtein();
    void displaySauce();
    void displayType();
    void displayBrew();
};

#endif



// #ifndef HOST_H
// #define HOST_H

// #include "Order.h"
// #include "Item.h"
// // #include "Manager.h"

// class Host {
// public:
//     void processOrder(const Order& order);
//     void displayMenu(const Item& item);
//     void displayOrderStatus(const Order& order);

// // private:
// //     Manager manager;
// };

// #endif