#pragma once

#include <memory>
#include "BeverageDecorator.hpp"

class Latte : public BeverageDecorator
{
public:
    Latte(std::unique_ptr<Beverage>&& beverage);
    std::string getDescription() const override;
    double cost() const override;
    
private:
    std::unique_ptr<Beverage> m_beverage;
};
