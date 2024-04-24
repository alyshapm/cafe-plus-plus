#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include <memory>
#include "Item.h"

class Patron;

class Order {
    std::vector<std::shared_ptr<Item>> items;
    std::weak_ptr<Patron> patron;

public:
    void addItem(const std::shared_ptr<Item>& item);
    std::vector<std::shared_ptr<Item>> getItems() const;

    void setPatron(const std::shared_ptr<Patron>& ptr) { patron = ptr; }
    std::shared_ptr<Patron> getPatron() const { return patron.lock(); }
};

#endif


// #ifndef ORDER_H
// #define ORDER_H

// #include <vector>
// #include <string>

// class Item;

// enum class OrderStatus {
//     Pending,
//     InProgress,
//     Completed,
//     Cancelled
// };

// class Order {
// private:
//     int orderID;
//     std::vector<Item> items;
//     std::string patronId;
//     double totalOrder;
//     OrderStatus orderStatus;

// public:
//     Order(int id, const std::string& patronId, const std::vector<Item>& items);
//     void updateOrderStatus(OrderStatus status);
//     double calculateTotal();
//     std::string getStatusAsString() const;

//     int getOrderID() const {
//         return orderID;
//     }

//     void setOrderStatus(const std::string& status);

// };

// #endif