#include "Decaff.hpp"


Decaff::Decaff(std::unique_ptr<Beverage>&& beverage)
    : m_beverage{ beverage.release() }
{
}

std::string Decaff::getDescription() const
{
    return m_beverage->getDescription() + ", Decaff";
}

double Decaff::cost() const
{
    return m_beverage->cost() + 0.49;
}
