#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
public:
    virtual ~Item() = default;
    virtual std::string getDescription() const = 0; // Pure virtual function
};

#endif

// // Item.h
// #ifndef ITEM_H
// #define ITEM_H
// using namespace std;
// #include <string>

// enum class ItemStatus {
//     Available,
//     OutOfStock,
//     Discontinued
// };
// enum class ItemType {
//     Food,
//     Drink
// };

// class Item {
// private:
//     int itemID;
//     ItemType itemType; // what is this.. also update uml to be string not bool
//     string itemName;
//     string itemDescription;
//     int itemStock;
//     double itemPrice;
//     ItemStatus itemStatus;

// public:
//     Item(int id, ItemType type, const string& name, const string& description, int stock, double price, ItemStatus status);
    
//     void addItem();
//     void removeItem();
//     int checkItemStock() const;

//     // adding getter methods; UML to be updated
//     int getItemID() const {
//         return itemID;
//     };
//     string getItemName() const  {
//         return itemName;
//     };
//     double getItemPrice() const {
//         return itemPrice;
//     };
//     string getItemDescription() const {
//         return itemDescription;
//     };
//     ItemStatus getItemStatus() const {
//         return itemStatus;
//     };
//     ItemType getItemType() const {
//         return itemType;
//     }
// };

// #endif // ITEM_H
