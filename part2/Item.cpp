#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Item {
    private:
        int itemID;
        bool itemType;
        string itemName;
        string itemDescription;
        int itemStock;
        double itemPrice;
        // enum itemStatus;
    
    public:
        void addItem();
        void removeItem();
        bool deactivateSession();
        int checkItemStock();
};