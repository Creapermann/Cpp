#pragma once
#include <string>
#include "Beverage.hpp"


class Espresso : public Beverage
{
public:
    double cost() const override;
    std::string getDescription() const override;
};