#ifndef PATRON_H
#define PATRON_H

#include <string>
#include <vector>
#include "Order.h"

class Patron {
    std::string name;
    std::vector<Order> orderHistory;

public:
    Patron(const std::string& name) : name(name) {}

    void placeOrder(const Order& order);
    std::string getName() const { return name; }
    const std::vector<Order>& getOrderHistory() const { return orderHistory; }
};

#endif
