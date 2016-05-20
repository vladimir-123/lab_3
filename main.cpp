#include "rational_number.h"

int main(int argc, char const *argv[])
{ 
    int temp;
/*
    std::cout << "Zero\n";
    TRationalNum zeroNum; // ноль
    temp = zeroNum.GetNumerator();
    std::cout << "Num " << temp << "\n";
    temp = zeroNum.GetDenominator();
    std::cout << "Den " << temp << "\n";
    
    std::cout << "Some number\n";
    TRationalNum anyNum(5, 4); // иницализация дробного числа
    temp = anyNum.GetNumerator();
    std::cout << "Num " << temp << "\n";
    temp = anyNum.GetDenominator();
    std::cout << "Den " << temp << "\n";
    
    std::cout << "Whole number\n";
    TRationalNum wholeNum(9); // иницализация целого числа
    temp = wholeNum.GetNumerator();
    std::cout << "Num " << temp << "\n";
    temp = wholeNum.GetDenominator();
    std::cout << "Den " << temp << "\n";

    std::cout << "A copy\n";
    TRationalNum rational1(wholeNum); // иницализация дробного числа
    temp = rational1.GetNumerator();
    std::cout << "Num " << temp << "\n";
    temp = rational1.GetDenominator();
    std::cout << "Den " << temp << "\n";

    std::cout << "9/3\n";
    std::cout << "Whole part\n";
    TRationalNum rational2(9, 3); // целая часть
    int wholePartOfRational2 = rational2.GetWholePart();
    std::cout << "Whole part " << wholePartOfRational2 << "\n";

    std::cout << "Reduce\n";
    TRationalNum rational3(1071, 462);
    std::cout << CommonDiv(rational3.GetNumerator(), rational3.GetDenominator()) << "\n";
    temp = rational3.GetNumerator();
    std::cout << "Num " << temp << "\n";
    temp = rational3.GetDenominator();
    std::cout << "Den " << temp << "\n";
    TRationalNum rational3Reduced = rational3.Reduce();
    temp = rational3Reduced.GetNumerator();
    std::cout << "Num " << temp << "\n";
    temp = rational3Reduced.GetDenominator();
    std::cout << "Den " << temp << "\n";

    std::cout << "Get reduced numerator\n";
    TRationalNum rational4(70, 105);
    std::cout << rational4.GetReducedNumerator() << "\n";
*/
/*
    TRationalNum First(3, 5);
    TRationalNum Second(1, 2);

    TRationalNum Result = First.Reduce();
    temp = Result.GetNumerator();
    std::cout << "Num " << temp << "\n";
    temp = Result.GetDenominator();
    std::cout << "Den " << temp << "\n";
*/
/*
    TRationalNum Result2(2 + First);
    temp = Result2.GetNumerator();
    std::cout << "Num " << temp << "\n";
    temp = Result2.GetDenominator();
    std::cout << "Den " << temp << "\n";


    TRationalNum TRNFirst(2, 5);
    TRationalNum TRNSecond  = TRNFirst;
    temp = TRNSecond.GetNumerator();
    std::cout << "Num " << temp << "\n";
    temp = TRNSecond.GetDenominator();
    std::cout << "Den " << temp << "\n";
*/
    TRationalNum myFirst(3, 5);
    TRationalNum mySecond(1, 2);
    TRationalNum Result3 = mySecond + 2;
    std::cout << Result3 << "\n";
/*
    temp = myResult.GetNumerator();
    std::cout << "Num " << temp << "\n";
    temp = myResult.GetDenominator();
    std::cout << "Den " << temp << "\n";
*/
    return 0;
}






















