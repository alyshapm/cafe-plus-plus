#ifndef SANDWICH_H
#define SANDWICH_H

#include "Food.h"

enum class Vegetables {
    Lettuce,
    Tomato,
    Onion,
    Cucumber
};

enum class Protein {
    Turkey,
    Ham,
    Chicken,
    Tofu
};

enum class Sauce {
    Mayonnaise,
    Mustard,
    Ketchup,
    Ranch
};

class Sandwich : public Food {
private:
    Vegetables vegetableChoice;
    Protein proteinChoice;
    Sauce sauceChoice;

public:
    // Constructor that specifies a default description
    Sandwich(const std::string& desc, Vegetables veg, Protein protein, Sauce sauce);

    std::string getDescription() const override;
    
    Vegetables getVegetable() const;
    Protein getProtein() const;
    Sauce getSauce() const;
};

#endif
