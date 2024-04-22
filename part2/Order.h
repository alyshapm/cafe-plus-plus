#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include <string>

class Item;

enum class OrderStatus {
    Pending,
    InProgress,
    Completed,
    Cancelled
};

class Order {
private:
    int orderID;
    std::vector<Item> items;
    std::string patronId;
    double totalOrder;
    OrderStatus orderStatus;

public:
    Order(int id, const std::string& patronId, const std::vector<Item>& items);
    void updateOrderStatus(OrderStatus status);
    double calculateTotal();
    std::string getStatusAsString() const;

    int getOrderID() const {
        return orderID;
    }

    void setOrderStatus(const std::string& status);

};

#endif