#ifndef HOST_H
#define HOST_H

#include "Order.h"
#include "Item.h"
// #include "Manager.h"

class Host {
public:
    void processOrder(const Order& order);
    void displayMenu(const Item& item);
    void displayOrderStatus(const Order& order);

// private:
//     Manager manager;
};

#endif
