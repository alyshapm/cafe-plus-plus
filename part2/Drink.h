#ifndef DRINK_H
#define DRINK_H

#include "Item.h"

class Drink : public Item {
protected:
    std::string description;

public:
    Drink();
    Drink(const std::string& desc);
    virtual ~Drink() = default;
    std::string getDescription() const;
};

#endif
