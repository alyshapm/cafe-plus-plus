#ifndef MANAGER_H
#define MANAGER_H

#include <queue>
#include "Order.h"
#include "Host.h"
#include "Item.h"
// #include "FoodMaker.h"
// #include "CoffeeMaker.h"


class Manager {
public:
    // Manager(Host* host);
    bool checkItemType(const Item& item);
    void receiveOrderFromHost(const Order& order);
    void assignOrder(const Order& order);
    void updateOrderStatus(Order& order, const std::string& status);

private:
    std::queue<Order> orderQueue;
    // Host* host;
    // FoodMaker foodMaker;
    // CoffeeMaker coffeeMaker;
};

#endif