#include "Snack.h"

Snack::Snack(const std::string& desc, SnackType type) : Food(desc), snackType(type) {}

std::string Snack::getDescription() const {
    std::string baseDescription = Food::getDescription();

    std::string snackTypeString;
    switch (snackType) {
        case SnackType::Chips:
            snackTypeString = "Chips";
            break;
        case SnackType::Cookies:
            snackTypeString = "Cookies";
            break;
        case SnackType::Chocolates:
            snackTypeString = "Chocolates";
            break;
        default:
            snackTypeString = "N/A";
            break;
    }

    return baseDescription + " (Snack)";
}

SnackType Snack::getSnackType() const {
    return snackType;
}
