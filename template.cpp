/* This file contains basic understanding of function and class templates in C++, including variadic
templates. */

#include <iostream>
#include <cstring>
using namespace std;

template<typename T>
T maxOfTwo(T x, T y)
{
    return x > y ? x : y ;
}

template<>
string maxOfTwo<string>(string a, string b)
{
    cout<< endl << "string template specialization" <<endl;
    return a.length() > b.length() ? a : b;
}

template<typename T, typename U>
class Pair{
    T x;
    U y;
    
    public:
    Pair(T a, U b) : x(a), y(b) {}
    void printVal()
    {
        cout << "First Value : " << x << endl;
        cout << "Second Value : " << y << endl;
    }
};

template<>
class Pair<string, string>{
    string x;
    string y;
    
    public:
    Pair(string a, string b) : x(a), y(b) {}
    void printVal()
    {
        cout << "Full Name : " << x << " " << y << endl;
    }
};

template<typename T>
T sum(T num)
{
    return num;
}
template<typename T, typename... Args>
T sum(T start, Args... args)
{
    return start + sum(args...);
}

int main()
{
    cout << "Max of two integers is " << maxOfTwo(5,9) << endl;
    cout << "Max of two float is " << maxOfTwo(1.5,0.9) << endl;
    cout << "Max of two strings is " << maxOfTwo<string>("Bob", "John") << endl;
    
    Pair<int, float> pair1(1,2.1f);
    pair1.printVal();
    
    Pair<string, string> pair2("Adhi","KG");
    pair2.printVal();
    
    cout << "Sum is " << sum(65,1,2) << endl;
    return 0;
}
