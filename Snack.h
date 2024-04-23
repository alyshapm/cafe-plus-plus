#ifndef SNACK_H
#define SNACK_H

#include "Food.h"

class Snack : public Food {
public:
    // Constructor that specifies a default description
    Snack(const std::string& desc = "Generic Snack");
    std::string getDescription() const override;
};

#endif
