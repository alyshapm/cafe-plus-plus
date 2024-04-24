#ifndef COFFEE_H
#define COFFEE_H

#include "Drink.h"

class Coffee : public Drink {
protected:
    std::string coffeeType;
    int sugar;
public:
    Coffee(const std::string& coffeeType, int sugar);
    virtual std::string getDescription() const override;
};

#endif
