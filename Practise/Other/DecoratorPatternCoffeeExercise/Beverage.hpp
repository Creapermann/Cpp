#pragma once

#include <string>

class Beverage
{
public:
    virtual ~Beverage() = default;
    virtual std::string getDescription() const;
    virtual double cost() const = 0;
};