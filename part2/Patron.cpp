#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Patron {
    private:
        int patronID;
        // datetime patronEntryTime;
        // datetime patronExitTime;
        // vector<Item> cart;
        bool patronStatus;
    
    public:
        void newSession();
        void endSession();
        void addToCart();
        void removeFromCart();
        void submitOrder();
};
