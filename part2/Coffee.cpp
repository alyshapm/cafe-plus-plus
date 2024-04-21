#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Coffee {
    private:
        string coffeeName;
        string coffeeType;
        string coffeeBean;
        string brewingMethod;
        int pullTime;
        int brewtingTime;

    public:
        int takeOrder();
        bool deactivateSession();
};