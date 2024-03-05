#include "fraction.hpp"
#include "utils.hpp"

#include <iostream>

// Fraction operator+(Fraction const &a, Fraction const &b)
// {
//     return simplify({a.numerator * b.denominator + b.numerator * a.denominator,
//                      a.denominator * b.denominator});
// }

// Fraction add(Fraction const& f1, Fraction const& f2) {
//     Fraction result {
//         f1.numerator * f2.denominator + f2.numerator * f1.denominator
//         f1.denominator * f2.denominator
//     };

//     return simplify(result);
// }

// Fraction operator-(Fraction const &f1, Fraction const &f2)
// {
//     return simplify({f1.numerator * f2.denominator - f2.numerator * f1.denominator,
//                      f1.denominator * f2.denominator});
// }

// Fraction operator*(Fraction const &f1, Fraction const &f2)
// {
//     return simplify({f1.numerator * f2.numerator,
//                      f1.denominator * f2.denominator});
// }

// Fraction operator/(Fraction const &f1, Fraction const &f2)
// {
//     return simplify({f1.numerator * f2.denominator,
//                      f1.denominator * f2.numerator});
// }

bool operator==(Fraction const &f1, Fraction const &f2)
{
    return {f1.numerator == f2.numerator && f1.denominator == f2.denominator};
}

bool operator!=(Fraction const &f1, Fraction const &f2)
{
    return !(f1 == f2);
}

bool operator<(Fraction const &f1, Fraction const &f2)
{
    return {f1.numerator / f1.denominator < f2.numerator / f2.denominator};
}

bool operator>(Fraction const &f1, Fraction const &f2)
{
    return !(f1 < f2);
}

bool operator<=(Fraction const &f1, Fraction const &f2)
{
    return {f1 < f2 || f1 == f2};
}

bool operator>=(Fraction const &f1, Fraction const &f2)
{
    return {!(f1 < f2) || f1 == f2};
}

Fraction Fraction::operator+=(Fraction const &a)
{
    numerator += numerator * a.denominator + denominator * a.numerator - numerator;
    denominator += a.denominator * denominator - denominator;
    return simplify(*this);
};

Fraction operator+(Fraction a, Fraction const &b)
{
    a += b;
    return a;
};

Fraction Fraction::operator-=(Fraction const &a)
{
    numerator -= numerator * a.denominator + denominator * a.numerator - numerator;
    denominator -= a.denominator * denominator - denominator;
    return simplify(*this);
};

Fraction operator-(Fraction a, Fraction const &b)
{
    a -= b;
    return a;
};

Fraction Fraction::operator*=(Fraction const &f1)
{
    numerator *= f1.numerator;
    denominator *= f1.denominator;
    return simplify(*this);
};

Fraction operator*(Fraction f1, Fraction const &f2)
{
    f1 *= f2;
    return f1;
};

Fraction Fraction::operator/=(Fraction const &f1)
{
    numerator *= f1.denominator;
    denominator *= f1.numerator;
    return simplify(*this);
};

Fraction operator/(Fraction f1, Fraction const &f2)
{
    f1 /= f2;
    return f1;
};

std::ostream &operator<<(std::ostream &os, Fraction const &f)
{
    return os << f.numerator << "/" << f.denominator;
};

float Fraction::to_float() const
{
    return static_cast<float>(numerator) / static_cast<float>(denominator);
};

Fraction::operator float() const
{
    return to_float();
}