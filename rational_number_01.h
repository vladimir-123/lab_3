#pragma once
#include <iostream>

class TRationalNum {
private:
    int Numerator;
    unsigned int Denominator;
public:
    TRationalNum();
    TRationalNum(int num, unsigned int denum = 1);
    TRationalNum(const TRationalNum& otherRational);
    int GetNumerator() const;
    int GetDenominator() const;
    TRationalNum Reduce() const;
    int GetReducedNumerator() const;
    int GetWholePart() const;
    TRationalNum operator=(const TRationalNum& otherRational);
    TRationalNum operator+(const TRationalNum& otherRational) const;
    TRationalNum operator-() const;
    TRationalNum operator+() const; // унарный оператор +
    TRationalNum operator*(const TRationalNum& mult) const;
    TRationalNum Reciprocal() const;
    TRationalNum& operator+=(const TRationalNum& otherRational);
    TRationalNum& operator++();
    TRationalNum operator++(int);
    TRationalNum& operator--();
    TRationalNum operator--(int);
    operator double() const;
};

int CommonDiv(int a, int b);
TRationalNum operator+(int a, const TRationalNum& summand);
TRationalNum operator-(const TRationalNum& FirstValue, const TRationalNum& SecondValue);
TRationalNum operator/(const TRationalNum& RDivident, const TRationalNum& RDivisor);
bool operator==(const TRationalNum& FirstValue, const TRationalNum& SecondValue);
std::ostream& operator<<(std::ostream& os, const TRationalNum& RationalValue);
void operator-=(TRationalNum& RAugend, const TRationalNum& RAddend);
void operator*=(TRationalNum& RMultiplier, const TRationalNum& RMultiplicand);
void operator/=(TRationalNum& RDivident, const TRationalNum& RDivisor);
bool operator!=(const TRationalNum& FirstValue, const TRationalNum& SecondValue);
bool operator<(const TRationalNum& FirstValue, const TRationalNum& SecondValue);
bool operator>(const TRationalNum& FirstValue, const TRationalNum& SecondValue);
bool operator<=(const TRationalNum& FirstValue, const TRationalNum& SecondValue);
bool operator>=(const TRationalNum& FirstValue, const TRationalNum& SecondValue);
TRationalNum operator--(const TRationalNum& RValue);
