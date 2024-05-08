#include "Sandwich.h"

Sandwich::Sandwich(const std::string& desc, const std::vector<VegetableChoice>& veggies,
                   const std::vector<ProteinChoice>& proteins, const std::vector<SauceChoice>& sauces)
    : Food(desc), vegetableChoices(veggies), proteinChoices(proteins), sauceChoices(sauces) {}

std::string Sandwich::getDescription() const {
    std::string baseDescription = Food::getDescription();
    std::string vegString, proteinString, sauceString;

    for (const auto& veg : vegetableChoices) {
        switch (veg) {
            case VegetableChoice::Lettuce: vegString += "Lettuce + "; break;
            case VegetableChoice::Tomato: vegString += "Tomato + "; break;
            case VegetableChoice::Onion: vegString += "Onion + "; break;
            case VegetableChoice::Cucumber: vegString += "Cucumber + "; break;
        }
    }
    if (!vegetableChoices.empty()) {
        vegString = vegString.substr(0, vegString.size() - 3);
    } else {
        vegString = "None";
    }

    for (const auto& protein : proteinChoices) {
        switch (protein) {
            case ProteinChoice::Turkey: proteinString += "Turkey + "; break;
            case ProteinChoice::Ham: proteinString += "Ham + "; break;
            case ProteinChoice::Chicken: proteinString += "Chicken + "; break;
            case ProteinChoice::Tofu: proteinString += "Tofu + "; break;
        }
    }
    if (!proteinChoices.empty()) {
        proteinString = proteinString.substr(0, proteinString.size() - 3);
    } else {
        proteinString = "None";
    }

    for (const auto& sauce : sauceChoices) {
        switch (sauce) {
            case SauceChoice::Mayonnaise: sauceString += "Mayonnaise + "; break;
            case SauceChoice::Mustard: sauceString += "Mustard + "; break;
            case SauceChoice::Ketchup: sauceString += "Ketchup + "; break;
            case SauceChoice::Ranch: sauceString += "Ranch + "; break;
        }
    }
    if (!sauceChoices.empty()) {
        sauceString = sauceString.substr(0, sauceString.size() - 3);
    } else {
        sauceString = "None";
    }

    return baseDescription + " (Sandwich with " + vegString + " + " + proteinString + " + " + sauceString + ")";
}

std::vector<VegetableChoice> Sandwich::getVegetables() const {
    return vegetableChoices;
}

std::vector<ProteinChoice> Sandwich::getProteins() const {
    return proteinChoices;
}

std::vector<SauceChoice> Sandwich::getSauces() const {
    return sauceChoices;
}
