#include "Tea.h"

Tea::Tea(const std::string& desc, TeaType type, TeaBrew brew)
    : Drink(desc), teaType(type), teaBrew(brew) {}

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

    return baseDescription + " (" + typeString + " " + brewString + ")";
}

TeaType Tea::getType() const {
    return teaType;
}

TeaBrew Tea::getBrew() const {
    return teaBrew;
}
