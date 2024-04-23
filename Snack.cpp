#include "Snack.h"

// Implementing the constructor
Snack::Snack(const std::string& desc) : Food(desc) {}

// Optionally override the getDescription method
std::string Snack::getDescription() const {
    // Call the base class getDescription to get the basic description
    std::string baseDescription = Food::getDescription();
    return baseDescription + " (snack)"; // Append "(snack)" to distinguish it
}
