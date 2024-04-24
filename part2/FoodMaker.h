#ifndef FOODMAKER_H
#define FOODMAKER_H

#include "Maker.h"
#include "Food.h"
#include <iostream>

class FoodMaker : public Maker {
public:
    void processItem(const std::shared_ptr<Order>& order) override;
};

#endif