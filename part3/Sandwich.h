#ifndef SANDWICH_H
#define SANDWICH_H

#include "Food.h"
#include <vector>

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
    std::vector<VegetableChoice> vegetableChoices;
    std::vector<ProteinChoice> proteinChoices;
    std::vector<SauceChoice> sauceChoices;

public:
    Sandwich(const std::string& desc, const std::vector<VegetableChoice>& veggies,
             const std::vector<ProteinChoice>& proteins, const std::vector<SauceChoice>& sauces);

    std::string getDescription() const override;

    std::vector<VegetableChoice> getVegetables() const;
    std::vector<ProteinChoice> getProteins() const;
    std::vector<SauceChoice> getSauces() const;
};

#endif
