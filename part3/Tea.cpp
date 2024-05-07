#include "Tea.h"

Tea::Tea(const std::string& desc, TeaType type, TeaBrew brew, int sugar)
    : Drink(desc), teaType(type), teaBrew(brew), sugar(sugar) {} // Updated constructor

std::string Tea::getDescription() const {
    std::string baseDescription = Drink::getDescription();

    std::string typeString = (teaType == TeaType::Hot) ? "Hot" : "Iced";
    std::string brewString;
    switch (teaBrew) {
        case TeaBrew::Black:
            brewString = "Black Tea";
            break;
        case TeaBrew::EarlGrey:
            brewString = "Earl Grey Tea";
            break;
        case TeaBrew::Osmanthus:
            brewString = "Osmanthus Tea";
            break;
        case TeaBrew::Green:
            brewString = "Green Tea";
            break;
        case TeaBrew::Jasmine:
            brewString = "Jasmine Tea";
            break;
        default:
            brewString = "Unknown";
            break;
    }

    return baseDescription + " (" + typeString + " " + brewString + ") with " + std::to_string(sugar) + " sugar cubes"; // Include sugar cubes in description
}

TeaType Tea::getType() const {
    return teaType;
}

TeaBrew Tea::getBrew() const {
    return teaBrew;
}

int Tea::getSugar() const {
    return sugar;
}
