#ifndef MANAGER_H
#define MANAGER_H

#include "FoodMaker.h"
#include "CoffeeMaker.h"
#include "Patron.h"
#include <memory>
#include <vector>

class Host;  // Forward declaration of Host

class Manager {
    std::shared_ptr<Host> host;
    std::vector<std::shared_ptr<Patron>> patrons;

    FoodMaker foodMaker;
    CoffeeMaker coffeeMaker;
public:
    Manager();
    void setHost(std::shared_ptr<Host> hst);
    void processOrder(const std::string& patronName, const std::shared_ptr<Order>& order);

    void addPatron(const std::shared_ptr<Patron>& patron);
    std::shared_ptr<Patron> getPatron(const std::string& name);
    std::pair<std::string, std::string> getPatronNameAndID(const std::shared_ptr<Order>& order);
};

#endif

// #ifndef MANAGER_H
// #define MANAGER_H

// #include <queue>
// #include "Order.h"
// #include "Host.h"
// #include "Item.h"
// // #include "FoodMaker.h"
// // #include "CoffeeMaker.h"


// class Manager {
// public:
//     // Manager(Host* host);
//     bool checkItemType(const Item& item);
//     void receiveOrderFromHost(const Order& order);
//     void assignOrder(const Order& order);
//     void updateOrderStatus(Order& order, const std::string& status);

// private:
//     std::queue<Order> orderQueue;
//     // Host* host;
//     // FoodMaker foodMaker;
//     // CoffeeMaker coffeeMaker;
// };

// #endif