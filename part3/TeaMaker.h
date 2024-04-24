#ifndef TEAMAKER_H
#define TEAMAKER_H

#include "Maker.h"
#include "Tea.h"
#include <iostream>
#include <memory>
#include <vector>

class TeaMaker : public Maker {
public:
    void processItem(const std::shared_ptr<Order>& order) override;
};

#endif
