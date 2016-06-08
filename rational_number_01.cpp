#include "rational_number.h"

TRationalNum::TRationalNum(): Numerator(0), Denominator(1) {}

TRationalNum::TRationalNum(int num, unsigned int denum):
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
    return Numerator / Denominator; //  если числитель меньше то он вернет ноль
}                                   // тк это int, у методов класса есть доступ к закрытым данным

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
// !!!!! почему здесь возвращаемый объект это не адресс???
TRationalNum TRationalNum::operator=(const TRationalNum& otherRational) {
    Numerator = otherRational.GetNumerator();
    Denominator = otherRational.GetDenominator();
    return *this;
}

TRationalNum& TRationalNum::operator+=(const TRationalNum& otherRational) {
    if (Denominator == otherRational.GetDenominator()) {
        Numerator += otherRational.GetNumerator();
    } else {
        Numerator = Numerator * otherRational.GetDenominator() + otherRational.GetNumerator() * Denominator;
        Denominator *= otherRational.GetDenominator();
    }
    return *this; 
}

TRationalNum TRationalNum::operator+(const TRationalNum& otherRational) const {
    TRationalNum temp(*this); 
    temp += otherRational;  
    return temp;    
}

TRationalNum operator+(int a, const TRationalNum& summand) {
    return summand + TRationalNum(a);
}
// унарные операторы (минус был, плюс добавил после замечания)
TRationalNum TRationalNum::operator-() const {
    TRationalNum TRNNegative(-GetNumerator(), GetDenominator());
    return TRNNegative;
}

TRationalNum TRationalNum::operator+() const {
    return *this;
}

TRationalNum operator-(const TRationalNum& FirstValue, const TRationalNum& SecondValue) {
    return FirstValue + (-SecondValue);
}

TRationalNum TRationalNum::operator*(const TRationalNum& mult) const {
    TRationalNum RProduct(GetNumerator() * mult.GetNumerator(),
        GetDenominator() * mult.GetDenominator());
    return RProduct;
}
// это перевернутая дробь
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

TRationalNum& TRationalNum::operator++() {
    *this += TRationalNum(1, 1);
    return *this;
}

TRationalNum TRationalNum::operator++(int) {
    TRationalNum temp(*this);
    ++(*this);
    return temp;
}

std::ostream& operator<<(std::ostream& os, const TRationalNum& RationalValue) {
    os << RationalValue.GetNumerator() << '/' << RationalValue.GetDenominator();
    return os;
}

void operator-=(TRationalNum& RAugend, const TRationalNum& RAddend) {
    RAugend += -RAddend;
}

TRationalNum& TRationalNum::operator--() {
    *this -= TRationalNum(1, 1);
    return *this;
}

TRationalNum TRationalNum::operator--(int) {
    TRationalNum temp(*this);
    --(*this);
    return temp;
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

TRationalNum::operator double() const {
    return static_cast<double>(Numerator) / Denominator;
}


