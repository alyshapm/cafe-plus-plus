#include "Item.h"

#include <iostream>
#include <string>
#include <vector>
using namespace std;

Item::Item(int id, ItemType type, const string& name, const string& description, int stock, double price, ItemStatus status)
    : itemID(id), itemType(type), itemName(name), itemDescription(description), itemStock(stock), itemPrice(price), itemStatus(status) {
    // Constructor body (if needed)
}

void Item::addItem() {
    // Implementation
}

void Item::removeItem() {
    // Implementation
}

bool Item::deactivateSession(int patronID) {
    return false; // Placeholder
}

int Item::checkItemStock() const {
    return itemStock;
}
