#ifndef FOOD_H
#define FOOD_H

#include "Item.h"

class Food : public Item {
    std::string description;

public:
    Food(const std::string& desc);
    std::string getDescription() const override;
};

#endif