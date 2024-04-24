#ifndef BLACKCOFFEE_H
#define BLACKCOFFEE_H

#include "Coffee.h"

class BlackCoffee : public Coffee {
public:
    BlackCoffee(int sugar = 0) : Coffee("Black", sugar) {}
    std::string getDescription() const override {
        return Coffee::getDescription(); // Optionally add more specific description details
    }
};

#endif
