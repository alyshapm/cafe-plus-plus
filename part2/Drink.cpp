#include "Drink.h"

Drink::Drink() : description("") {}

Drink::Drink(const std::string& desc) : description(desc) {}

std::string Drink::getDescription() const {
    return description;
}
