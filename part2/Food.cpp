#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Food {
    private:
        string foodType;
        //datetime expirationDate;
        int calories;
        string ingredients;
    
    public:
        void createFood();
        int takeOrder();
        bool deactivateSession();
};