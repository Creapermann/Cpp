#pragma once
#include "Beverage.hpp"

class HouseBlend : public Beverage
{
public:
    double cost() const override;
    std::string getDescription() const override;
};
