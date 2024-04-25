#ifndef SANDWICH_H
#define SANDWICH_H

#include "Food.h"

enum class VegetableChoice {
    Lettuce,
    Tomato,
    Onion,
    Cucumber
};

enum class ProteinChoice {
    Turkey,
    Ham,
    Chicken,
    Tofu
};

enum class SauceChoice {
    Mayonnaise,
    Mustard,
    Ketchup,
    Ranch
};

class Sandwich : public Food {
private:
    VegetableChoice vegetableChoice;
    ProteinChoice proteinChoice;
    SauceChoice sauceChoice;

public:
    // Constructor that specifies a default description
    Sandwich(const std::string& desc, VegetableChoice veg, ProteinChoice protein, SauceChoice sauce);

    std::string getDescription() const override;
    
    VegetableChoice getVegetable() const;
    ProteinChoice getProtein() const;
    SauceChoice getSauce() const;
};

#endif
