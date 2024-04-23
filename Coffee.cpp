#include "Coffee.h"

Coffee::Coffee(const std::string& type, int sugar) : type(type), sugar(sugar) {}

// Define the getDescription method
std::string Coffee::getDescription() const {
    return type + " Coffee with " + std::to_string(sugar) + " sugar(s)";
}
