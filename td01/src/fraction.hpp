#pragma once

struct Fraction
{
    unsigned int numerator;
    unsigned int denominator;

    Fraction operator+=(Fraction const &a);
    Fraction operator-=(Fraction const &a);
    Fraction operator*=(Fraction const &f1);
    Fraction operator/=(Fraction const &f1);

    float to_float() const;
    operator float() const;
};

Fraction operator*(Fraction const &f1, Fraction const &f2);
Fraction operator/(Fraction const &f1, Fraction const &f2);
Fraction operator+(Fraction a, Fraction const &b);
Fraction operator-(Fraction a, Fraction const &b);
bool operator==(Fraction const &f1, Fraction const &f2);
bool operator!=(Fraction const &f1, Fraction const &f2);
bool operator<(Fraction const &f1, Fraction const &f2);
bool operator>(Fraction const &f1, Fraction const &f2);
bool operator<=(Fraction const &f1, Fraction const &f2);
bool operator>=(Fraction const &f1, Fraction const &f2);

std::ostream &operator<<(std::ostream &os, Fraction const &f);
