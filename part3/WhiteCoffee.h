#ifndef WHITECOFFEE_H
#define WHITECOFFEE_H

#include "Coffee.h"

enum class CoffeeType {
    Regular,
    Latte,
    Cappuccino,
    FlatWhite
};

enum class MilkType {
    Regular,
    Almond,
    Soy,
    Oat
};

class WhiteCoffee : public Coffee {
private:
    CoffeeType coffeeType;
    MilkType milkType;

public:
    WhiteCoffee(CoffeeType coffee = CoffeeType::Regular, MilkType milk = MilkType::Regular, int sugar = 0);
    std::string getDescription() const override;
    CoffeeType getType() const;
    MilkType getMilk() const;
};

#endif
