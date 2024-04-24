#include "Patron.h"

void Patron::placeOrder(const Order& order) {
    orderHistory.push_back(order);
}
