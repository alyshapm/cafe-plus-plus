#include "Order.h"

void Order::addItem(const std::shared_ptr<Item>& item) {
    items.push_back(item);
}

std::vector<std::shared_ptr<Item>> Order::getItems() const {
    return items;
}


// #include "Order.h"
// #include "Item.h" // Ensure this is defined and includes price information if used in calculateTotal()

// Order::Order(int id, const std::string& patronId, const std::vector<Item>& items)
//     : orderID(id), patronId(patronId), items(items), totalOrder(0.0), orderStatus(OrderStatus::Pending) {
//     totalOrder = calculateTotal(); // Calculate the total order at initialization
// }

// void Order::updateOrderStatus(OrderStatus status) {
//     orderStatus = status;
// }

// double Order::calculateTotal() {
//     double total = 0.0;
//     for (const Item& item : items) {
//         total += item.getItemPrice(); // Assuming Item has a getPrice method
//     }
//     return total;
// }


// std::string Order::getStatusAsString() const {
//     switch (orderStatus) { // Assuming orderStatus is an OrderStatus enum member variable
//         case OrderStatus::Pending:    return "Pending";
//         case OrderStatus::InProgress: return "In progress";
//         case OrderStatus::Completed:  return "Completed";
//         case OrderStatus::Cancelled:  return "Cancelled";
//         default:                      return "Unknown";
//     }
// }

// void Order::setOrderStatus(const std::string& status) {
//     if(status == "Pending") {
//         orderStatus = OrderStatus::Pending;
//     } else if(status == "In progress") {
//         orderStatus = OrderStatus::InProgress;
//     } else if(status == "Completed") {
//         orderStatus = OrderStatus::Completed;
//     } else if(status == "Cancelled") {
//         orderStatus = OrderStatus::Cancelled;
//     } else {
//         // handle error
//     }
// }