#include <iostream>
#include "fraction.hpp"

int main()
{
    Fraction f1{3, 4};
    Fraction f2{1, 2};

    std::cout << "f1 = ";
    std::cout << f1;
    std::cout << " f2 = ";
    std::cout << f2;
    std::cout << std::endl;

    Fraction f3{(f1 + f2)};
    Fraction f4{(f1 - f2)};
    Fraction f5{(f1 * f2)};
    Fraction f6{(f1 / f2)};

    std::cout << "add(f1, f2) = ";
    std::cout << f3;

    std::cout << std::endl
              << "sub(f1, f2) = ";
    std::cout << f4;

    std::cout << std::endl
              << "mul(f1, f2) = ";
    std::cout << f5;

    std::cout << std::endl
              << "div(f1, f2) = ";
    std::cout << f6;

    return 0;
}