#ifndef MAKER_H
#define MAKER_H

#include "Order.h"
#include <memory>

class Maker {
public:
    virtual ~Maker() {}

    // Process an order item
    virtual void processItem(const std::shared_ptr<Order>& order) = 0;
};

#endif
