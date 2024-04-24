#include "Sandwich.h"

Sandwich::Sandwich(const std::string& desc, Vegetables veg, Protein protein, Sauce sauce)
    : Food(desc), vegetableChoice(veg), proteinChoice(protein), sauceChoice(sauce) {}

std::string Sandwich::getDescription() const {
    std::string baseDescription = Food::getDescription();

    std::string vegString, proteinString, sauceString;

    switch (vegetableChoice) {
        case Vegetables::Lettuce:
            vegString = "Lettuce";
            break;
        case Vegetables::Tomato:
            vegString = "Tomato";
            break;
        case Vegetables::Onion:
            vegString = "Onion";
            break;
        case Vegetables::Cucumber:
            vegString = "Cucumber";
            break;
        default:
            vegString = "Unknown";
            break;
    }

    switch (proteinChoice) {
        case Protein::Turkey:
            proteinString = "Turkey";
            break;
        case Protein::Ham:
            proteinString = "Ham";
            break;
        case Protein::Chicken:
            proteinString = "Chicken";
            break;
        case Protein::Tofu:
            proteinString = "Tofu";
            break;
        default:
            proteinString = "Unknown";
            break;
    }

    switch (sauceChoice) {
        case Sauce::Mayonnaise:
            sauceString = "Mayonnaise";
            break;
        case Sauce::Mustard:
            sauceString = "Mustard";
            break;
        case Sauce::Ketchup:
            sauceString = "Ketchup";
            break;
        case Sauce::Ranch:
            sauceString = "Ranch";
            break;
        default:
            sauceString = "Unknown";
            break;
    }

    return baseDescription + " (Sandwich with " + vegString + " + " + proteinString + " + " + sauceString + ")";
}

Vegetables Sandwich::getVegetable() const {
    return vegetableChoice;
}

Protein Sandwich::getProtein() const {
    return proteinChoice;
}

Sauce Sandwich::getSauce() const {
    return sauceChoice;
}
