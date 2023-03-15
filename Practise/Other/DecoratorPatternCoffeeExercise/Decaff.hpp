#pragma once
#include <memory>
#include "BeverageDecorator.hpp"


class Decaff : public BeverageDecorator
{
public:
    Decaff(std::unique_ptr<Beverage>&& beverage);
    std::string getDescription() const override;
    double cost() const override;
    
private:
    std::unique_ptr<Beverage> m_beverage;
};