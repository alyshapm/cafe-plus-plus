#include "Food.h"

Food::Food(const std::string& desc) : description(desc) {}

std::string Food::getDescription() const {
    return description;
}