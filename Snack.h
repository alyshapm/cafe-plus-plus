#ifndef SNACK_H
#define SNACK_H

#include "Food.h"

enum class SnackType {
    Chips,
    Cookies,
    Chocolates
};

class Snack : public Food {
private:
    SnackType snackType;
public:
    // Constructor that specifies a default description
    Snack(const std::string& desc, SnackType type);
    std::string getDescription() const override;
    SnackType getSnackType() const;
};

#endif
