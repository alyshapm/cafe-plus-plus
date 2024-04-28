#include "WhiteCoffee.h"

WhiteCoffee::WhiteCoffee(CoffeeType coffee, MilkType milk, int sugar) 
        : Coffee("White", sugar), coffeeType(coffee), milkType(milk) {}

std::string WhiteCoffee::getDescription() const {
    std::string description = "White ";
    switch (coffeeType) {
        case CoffeeType::Regular:
            description += "Coffee";
            break;
        case CoffeeType::Latte:
            description += "Latte";
            break;
        case CoffeeType::Cappuccino:
            description += "Cappuccino";
            break;
        case CoffeeType::FlatWhite:
            description += "Flat White";
            break;
    }
    description += " with ";
    switch (milkType) {
        case MilkType::Regular:
            description += "regular milk";
            break;
        case MilkType::Almond:
            description += "almond milk";
            break;
        case MilkType::Soy:
            description += "soy milk";
            break;
        case MilkType::Oat:
            description += "oat milk";
            break;
    }
    description += " and " + std::to_string(sugar) + " blocks of sugar.";
    return description;
}

CoffeeType WhiteCoffee::getType() const {
    return coffeeType;
}

MilkType WhiteCoffee::getMilk() const {
    return milkType;
}
