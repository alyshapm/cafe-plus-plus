#ifndef TEA_H
#define TEA_H

#include "Drink.h"

enum class TeaType {
    Hot,
    Iced
};

enum class TeaBrew {
    Black,
    EarlGrey,
    Osmanthus,
    Green,
    Jasmine
};

class Tea : public Drink {
private:
    TeaType teaType;
    TeaBrew teaBrew;

public:
    Tea(const std::string& desc, TeaType teaType, TeaBrew teaBrew);
    std::string getDescription() const override;
    TeaType getType() const;
    TeaBrew getBrew() const;
};

#endif
