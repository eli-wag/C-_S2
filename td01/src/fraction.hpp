#pragma once

struct Fraction
{
    unsigned int numerator;
    unsigned int denominator;

    auto operator<=>(Fraction const &f1) const = default;
};

Fraction operator+(Fraction const &a, Fraction const &b);
Fraction operator-(Fraction const &f1, Fraction const &f2);
Fraction operator*(Fraction const &f1, Fraction const &f2);
Fraction operator/(Fraction const &f1, Fraction const &f2);
bool operator==(Fraction const &f1, Fraction const &f2);
bool operator!=(Fraction const &f1, Fraction const &f2);

std::ostream &operator<<(std::ostream &os, Fraction const &p);
