#ifndef HOST_H
#define HOST_H

#include "Order.h"
#include "BlackCoffee.h"
#include "WhiteCoffee.h"
#include "Patron.h"

#include <iostream>
#include <memory>

class Manager;

class Host {
    std::shared_ptr<Manager> manager;
public:
    Host(std::shared_ptr<Manager> mgr);
    void start();
    void takeOrder(const std::string& patronName);
    void notifyCompletion(const std::string& orderDetails);
    void displayOrderHistory(const std::string& patronName);
    void displayMenu();
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