/* This file contains dynamic memory support provided by the C++
Standard Library using smart pointers */

#include <iostream>
#include <memory>

using namespace std;

class Person{
    string name;
    int age;
    
    public:
    Person(string a, int b): name(a), age(b) {};
    
    ~Person()
    {
        cout << "Destructor invoked" << endl;
    }
};

int main()
{
    unique_ptr<Person>uPtr1 = make_unique<Person>("Adhi", 1);
    // unique_ptr<Person>uPtr1 (new Person("Adhi", 1));
    
    shared_ptr<Person>shPtr1 = make_shared<Person>("Adhithyan", 2);
    cout << shPtr1.use_count() << endl;
    
    shared_ptr<Person>shPtr2 = shPtr1;
    cout << shPtr2.use_count() << endl;
    
    weak_ptr<Person>wkPtr1 = shPtr2;
    cout << shPtr2.use_count() << endl;
    
    return 0;
}
