#ifndef COFFEEMAKER_H
#define COFFEEMAKER_H

#include "Order.h"

class CoffeeMaker {
public:
    void prepareCoffee(const std::shared_ptr<Order>& order);
};

#endif
