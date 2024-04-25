#include "Sandwich.h"

Sandwich::Sandwich(const std::string& desc, VegetableChoice veg, ProteinChoice protein, SauceChoice sauce)
    : Food(desc), vegetableChoice(veg), proteinChoice(protein), sauceChoice(sauce) {}

std::string Sandwich::getDescription() const {
    std::string baseDescription = Food::getDescription();

    std::string vegString, proteinString, sauceString;

    switch (vegetableChoice) {
        case VegetableChoice::Lettuce:
            vegString = "Lettuce";
            break;
        case VegetableChoice::Tomato:
            vegString = "Tomato";
            break;
        case VegetableChoice::Onion:
            vegString = "Onion";
            break;
        case VegetableChoice::Cucumber:
            vegString = "Cucumber";
            break;
        default:
            vegString = "Unknown";
            break;
    }

    switch (proteinChoice) {
        case ProteinChoice::Turkey:
            proteinString = "Turkey";
            break;
        case ProteinChoice::Ham:
            proteinString = "Ham";
            break;
        case ProteinChoice::Chicken:
            proteinString = "Chicken";
            break;
        case ProteinChoice::Tofu:
            proteinString = "Tofu";
            break;
        default:
            proteinString = "Unknown";
            break;
    }

    switch (sauceChoice) {
        case SauceChoice::Mayonnaise:
            sauceString = "Mayonnaise";
            break;
        case SauceChoice::Mustard:
            sauceString = "Mustard";
            break;
        case SauceChoice::Ketchup:
            sauceString = "Ketchup";
            break;
        case SauceChoice::Ranch:
            sauceString = "Ranch";
            break;
        default:
            sauceString = "Unknown";
            break;
    }

    return baseDescription + " (Sandwich with " + vegString + " + " + proteinString + " + " + sauceString + ")";
}

VegetableChoice Sandwich::getVegetable() const {
    return vegetableChoice;
}

ProteinChoice Sandwich::getProtein() const {
    return proteinChoice;
}

SauceChoice Sandwich::getSauce() const {
    return sauceChoice;
}
