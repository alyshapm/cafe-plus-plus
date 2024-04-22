// Item.h
#ifndef ITEM_H
#define ITEM_H

#include <string>

enum class ItemStatus {
    Available,
    OutOfStock,
    Discontinued
};
enum class ItemType {
    Food,
    Drink
};

class Item {
private:
    int itemID;
    ItemType itemType; // what is this.. also update uml to be string not bool
    string itemName;
    string itemDescription;
    int itemStock;
    double itemPrice;
    ItemStatus itemStatus;

public:
    Item(int id, ItemType type, const string& name, const string& description, int stock, double price, ItemStatus status);
    
    void addItem();
    void removeItem();
    bool deactivateSession(int patronID);
    int checkItemStock() const;

    // adding getter methods; UML to be updated
    int getItemID() const {
        return itemID;
    };
    string getItemName() const  {
        return itemName;
    };
    double getItemPrice() const {
        return itemPrice;
    };
    string getItemDescription() const {
        return itemDescription;
    };
    ItemStatus getItemStatus() const {
        return itemStatus;
    };
    ItemType getItemType() const {
        return itemType;
    }
};

#endif // ITEM_H
