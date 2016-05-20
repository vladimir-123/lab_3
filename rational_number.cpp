#include "rational_number.h"

TRationalNum::TRationalNum(): Numerator(0), Denominator(1) {}

TRationalNum::TRationalNum(const int num, const int denum):
Numerator(num), Denominator(denum) {}

TRationalNum::TRationalNum(const TRationalNum& otherRational):
Numerator(otherRational.Numerator), Denominator(otherRational.Denominator) {}

int TRationalNum::GetNumerator() const {
    return Numerator;
}

int TRationalNum::GetDenominator() const {
    return Denominator;
}

int TRationalNum::GetWholePart() const{
    if (GetNumerator() > GetDenominator()) {//mb this.GetNumerator
        return GetNumerator() / GetDenominator();
    } else {
        return 0;
    }
}

int CommonDiv(int a, int b) {
    while (a && b) { // находит общий множитель
        a %= b;
        if (a) {
            b %= a;
        }
    }
    return b?b:a;
}

TRationalNum TRationalNum::Reduce() const {
    int commonDivisor = CommonDiv(GetNumerator(), GetDenominator());
    TRationalNum reducedRational(GetNumerator() / commonDivisor,
        GetDenominator() / commonDivisor);
    return reducedRational;
}

int TRationalNum::GetReducedNumerator() const {
    int commonDivisor = CommonDiv(GetNumerator(), GetDenominator());
    return Numerator / commonDivisor;
}

void TRationalNum::operator=(const TRationalNum& otherRational) {
    Numerator = otherRational.GetNumerator();
    Denominator = otherRational.GetDenominator();
}

TRationalNum TRationalNum::operator+(const TRationalNum& summand) const {
    if (GetDenominator() == summand.GetDenominator()) {
        TRationalNum Sum(GetNumerator() + summand.GetNumerator(),
            GetDenominator());
        return Sum;
    } else if (0 == GetDenominator() % summand.GetDenominator()) {
        int mult = GetDenominator() / summand.GetDenominator();
        TRationalNum Sum(GetNumerator() + summand.GetNumerator() * mult,
            GetDenominator());
        return Sum;
    } else  if (0 == summand.GetDenominator() % GetDenominator()) {
        int mult = summand.GetDenominator() / GetDenominator();
        TRationalNum Sum(GetNumerator() * mult + summand.GetNumerator(),
            summand.GetDenominator());
        return Sum;
    } else {
        TRationalNum Sum(GetNumerator() * summand.GetDenominator() +
            summand.GetNumerator() * GetDenominator(),
            GetDenominator() * summand.GetDenominator());
        return Sum;
    }
}

TRationalNum operator+(int a, const TRationalNum& summand) {
    return summand + a;
}

TRationalNum TRationalNum::operator-() const {
    TRationalNum TRNNegative(-GetNumerator(), GetDenominator());
    return TRNNegative;
}

TRationalNum operator-(const TRationalNum& FirstValue, const TRationalNum& SecondValue) {
    return FirstValue + (-SecondValue);
}

TRationalNum TRationalNum::operator*(const TRationalNum& mult) const {
    TRationalNum RProduct(GetNumerator() * mult.GetNumerator(),
        GetDenominator() * mult.GetDenominator());
    return RProduct;
}

TRationalNum TRationalNum::Reciprocal() const {
    TRationalNum TReciprocal(GetDenominator(), GetNumerator());
    return TReciprocal;
}

TRationalNum operator/(const TRationalNum& RDivident, const TRationalNum& RDivisor) {
    TRationalNum TQuotient = RDivident * RDivisor.Reciprocal();
    return TQuotient;
}

bool operator==(const TRationalNum& FirstValue, const TRationalNum& SecondValue) {
    TRationalNum FirRV = FirstValue.Reduce(); // First Reduced Value
    TRationalNum SecRV = SecondValue.Reduce(); // Second Reduced Value
    if (FirRV.GetNumerator() == SecRV.GetNumerator() &&
        FirRV.GetDenominator() == SecRV.GetDenominator()) {
        return true;
    } else {
        return false;
    }
}

TRationalNum operator++(const TRationalNum& RValue) {
    TRationalNum IncrRValue = RValue + 1;
    return IncrRValue;
}

std::ostream& operator<<(std::ostream& os, const TRationalNum& RationalValue) {
    os << RationalValue.GetNumerator() << '/' << RationalValue.GetDenominator();
    return os;
}

void operator+=(TRationalNum& RAugend, const TRationalNum& RAddend) {
    RAugend = RAugend + RAddend;
}

void operator-=(TRationalNum& RAugend, const TRationalNum& RAddend) {
    RAugend += -RAddend;
}

void operator*=(TRationalNum& RMultiplier, const TRationalNum& RMultiplicand) {
    RMultiplier = RMultiplier * RMultiplicand;
}

void operator/=(TRationalNum& RDivident, const TRationalNum& RDivisor) {
    RDivident *= RDivisor.Reciprocal();
}

bool operator!=(const TRationalNum& FirstValue, const TRationalNum& SecondValue) {
    return FirstValue == SecondValue ? false : true;
}

bool operator<(const TRationalNum& FirstValue, const TRationalNum& SecondValue) {
    if (FirstValue.GetNumerator() * SecondValue.GetDenominator() <
        SecondValue.GetNumerator() * FirstValue.GetDenominator() &&
        FirstValue != SecondValue) {
        return true;
    } else {
        return false;
    }
}

bool operator>(const TRationalNum& FirstValue, const TRationalNum& SecondValue) {
    return FirstValue < SecondValue || FirstValue == SecondValue ? 0 : 1;
}

bool operator<=(const TRationalNum& FirstValue, const TRationalNum& SecondValue) {
    return FirstValue < SecondValue || FirstValue == SecondValue ? 1 : 0;
}

bool operator>=(const TRationalNum& FirstValue, const TRationalNum& SecondValue) {
    return FirstValue > SecondValue || FirstValue == SecondValue ? 1 : 0;
}

TRationalNum operator--(const TRationalNum& RValue) {
    TRationalNum DecrRValue = RValue - 1;
    return DecrRValue;
}




