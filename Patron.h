#ifndef PATRON_H
#define PATRON_H

#include <string>
#include <vector>
#include <vector>
#include <ctime>
#include <random>

#include "Order.h"

class Patron {
    std::string patronName;
    std::string patronID;
    std::vector<Order> orderHistory;

public:
    Patron(const std::string& patronName) : patronName(patronName) {
        patronID = generateID();
    }

    void placeOrder(const Order& order);
    std::string getName() const { return patronName; }
    std::string getID() const { return patronID; }
    const std::vector<Order>& getOrderHistory() const { return orderHistory; }

private:
    std::string generateID() {
        std::string timestamp = std::to_string(time(nullptr)); // Get current timestamp
        std::string uniqueID = timestamp;

        // Generate a random number between 1000 and 9999
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1000, 9999);
        uniqueID += std::to_string(dis(gen));

        return uniqueID;
    }

};

#endif
