#ifndef RATIONAL_NUMBER_H_
#define RATIONAL_NUMBER_H_

#include <iostream>

class TRationalNum {
private:
    int Numerator;
    unsigned int Denominator;
public:
    TRationalNum();
    TRationalNum(const int num, const int denum = 1);
    TRationalNum(const TRationalNum& otherRational);
    int GetNumerator() const;
    int GetDenominator() const;
    TRationalNum Reduce() const;
    int GetReducedNumerator() const;
    int GetWholePart() const;
    void operator=(const TRationalNum& otherRational);
    TRationalNum operator+(const TRationalNum& summand) const;
    TRationalNum operator-() const;
    TRationalNum operator*(const TRationalNum& mult) const;
    TRationalNum Reciprocal() const;
    //operator double() {return Numerator / Denominator;} не могу написать функцию преобразования типов
};

int CommonDiv(int a, int b);
TRationalNum operator+(int a, const TRationalNum& summand);
TRationalNum operator-(const TRationalNum& FirstValue, const TRationalNum& SecondValue);
TRationalNum operator/(const TRationalNum& RDivident, const TRationalNum& RDivisor);
bool operator==(const TRationalNum& FirstValue, const TRationalNum& SecondValue);
TRationalNum operator++(const TRationalNum& RValue);
std::ostream& operator<<(std::ostream& os, const TRationalNum& RationalValue);
void operator+=(TRationalNum& RAugend, const TRationalNum& RAddend);
void operator-=(TRationalNum& RAugend, const TRationalNum& RAddend);
void operator*=(TRationalNum& RMultiplier, const TRationalNum& RMultiplicand);
void operator/=(TRationalNum& RDivident, const TRationalNum& RDivisor);
bool operator!=(const TRationalNum& FirstValue, const TRationalNum& SecondValue);
bool operator<(const TRationalNum& FirstValue, const TRationalNum& SecondValue);
bool operator>(const TRationalNum& FirstValue, const TRationalNum& SecondValue);
bool operator<=(const TRationalNum& FirstValue, const TRationalNum& SecondValue);
bool operator>=(const TRationalNum& FirstValue, const TRationalNum& SecondValue);
TRationalNum operator--(const TRationalNum& RValue);

#endif