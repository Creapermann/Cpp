#pragma once
#include "Beverage.hpp"

class BeverageDecorator : public Beverage
{
public:
    std::string getDescription() const override = 0;
};