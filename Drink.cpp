#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Drink {
    private:
        int drinkSize;
        string drinkCategory;
        int sugarLevel;
        string composition;
    
    public:
        void createDrink();
        int takeOrder();
};