#include <iostream>
#include <memory>
#include "Espresso.hpp"
#include "Latte.hpp"
#include "Decaff.hpp"
#include "HouseBlend.hpp"


int main()
{
    std::unique_ptr<Beverage> beverage = std::make_unique<Espresso>();
    beverage = std::make_unique<Latte>(std::move(beverage));
    beverage = std::make_unique<Decaff>(std::move(beverage));
    
    std::cout << "Beverage is: " + beverage->getDescription()
              << " and costs: " << beverage->cost() << std::endl;
    
    return 0;
}

