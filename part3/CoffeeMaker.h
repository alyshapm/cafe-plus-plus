#ifndef COFFEEMAKER_H
#define COFFEEMAKER_H

#include "Maker.h"
#include "Coffee.h"
#include <iostream>
#include <memory>
#include <vector>

class CoffeeMaker : public Maker {
public:
    void processItem(const std::shared_ptr<Order>& order) override;
};

#endif
