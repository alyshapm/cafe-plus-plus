#include "Coffee.h"

Coffee::Coffee(const std::string& coffeeType, int sugar) : coffeeType(coffeeType), sugar(sugar) {}

// Define the getDescription method
std::string Coffee::getDescription() const {
    return coffeeType + " Coffee with " + std::to_string(sugar) + " sugar(s)";
}
