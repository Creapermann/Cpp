#include "Latte.hpp"


Latte::Latte(std::unique_ptr<Beverage>&& beverage)
        : m_beverage(beverage.release())
{
}

std::string Latte::getDescription() const
{
    return m_beverage->getDescription() + ", Latte";
}

double Latte::cost() const
{
    return m_beverage->cost() + 0.20;
}
