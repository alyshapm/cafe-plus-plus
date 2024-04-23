#ifndef FOODMAKER_H
#define FOODMAKER_H

#include "Order.h"

class FoodMaker {
public:
    void prepareFood(const std::shared_ptr<Order>& order);
};

#endif