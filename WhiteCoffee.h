#ifndef WHITECOFFEE_H
#define WHITECOFFEE_H

#include "Coffee.h"

class WhiteCoffee : public Coffee {
public:
    WhiteCoffee(int sugar = 0) : Coffee("White", sugar) {} // Specifying type explicitly
    std::string getDescription() const override {
        return Coffee::getDescription(); // Optionally add more specific description details
    }
};

#endif
