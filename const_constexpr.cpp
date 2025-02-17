/* This file contains const and constexpr qualifiers in C++, including
purpose, correctness, consistency, conversion and casting. */

#include <iostream>

using namespace std;

constexpr double pi = 3.14;

constexpr double area_of_circle(double radius)
{
    return pi * radius * radius;
}
constexpr long long factorial(int number)
{
    return (number<=1)?1: number * factorial(number-1);
    
}
class ImmutablePoint {
    
    const int x, y;
    
    public:
    constexpr ImmutablePoint(int a, int b) : x(a), y(b) {}
    void print_coordinates () const
    {
        cout << "x is: " << x << " " << "y is: " << y << endl;
    }
};

class constCast{
    const int number;
    
    public:
    constCast(int num) : number(num) {}
    void printNumber()
    {
        cout << "Number is: " << number;
    }
    void modifyNumber(int num)
    {
        int& modifiedConstNumber = const_cast<int&>(number);
        modifiedConstNumber = num;
        cout << "Non Const Number is: " << modifiedConstNumber;
    }
    
};
int main()
{
    constexpr ImmutablePoint axis(5,6);
    axis.print_coordinates();
    constexpr double area_result = area_of_circle(5);
    cout << area_result;
    constexpr long long total = factorial(15);
    cout << "factorial answer:" << total << endl;
    constCast N1(5);
    N1.printNumber();
    N1.modifyNumber(10);
    N1.printNumber();
    return 0;
}
