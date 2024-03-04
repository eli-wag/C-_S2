#include "fraction.hpp"
#include "utils.hpp"

#include <iostream>

std::ostream &operator<<(std::ostream &os, Fraction const &p)
{
    return os << p.numerator << "/" << p.denominator << std::endl;
}

Fraction operator+(Fraction const &a, Fraction const &b)
{
    return simplify({a.numerator * b.denominator + b.numerator * a.denominator,
                     a.denominator * b.denominator});
}

// Fraction add(Fraction const& f1, Fraction const& f2) {
//     Fraction result {
//         f1.numerator * f2.denominator + f2.numerator * f1.denominator
//         f1.denominator * f2.denominator
//     };

//     return simplify(result);
// }

Fraction operator-(Fraction const &f1, Fraction const &f2)
{
    return simplify({f1.numerator * f2.denominator - f2.numerator * f1.denominator,
                     f1.denominator * f2.denominator});
}

Fraction operator*(Fraction const &f1, Fraction const &f2)
{
    return simplify({f1.numerator * f2.numerator,
                     f1.denominator * f2.denominator});
}

Fraction operator/(Fraction const &f1, Fraction const &f2)
{
    return simplify({f1.numerator * f2.denominator,
                     f1.denominator * f2.numerator});
}

bool operator==(Fraction const &f1, Fraction const &f2)
{
    return {f1.numerator == f2.numerator && f1.denominator == f2.denominator};
}

bool operator!=(Fraction const &f1, Fraction const &f2)
{
    return !(f1 == f2);
}

auto operator<=>(Fraction const &f1) const = default {};