#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Manager {
    private:
        // queue<order> orderQueue
    
    public:
        bool checkItemType();
        void receiveOrderFromHost();
        void assignOrder();
        void updateOrderStatus();
};