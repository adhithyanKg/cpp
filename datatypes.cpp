/* This files contains basic C++ types and the rules for their declaration and use. 
   int, float, char, bool, string, array, class, structure, union, pointer, and vector.
*/

#include <iostream>
#include <vector>
using namespace std;

class BusInfo{
    float fareAmount = 10;
    int busNumber = 30;
    string transitName = "GO";
    string sourceRoute = "University of Waterloo";
    string destinationRoute = "Bramalea";
    
    public:
    void print(){
        cout << "Bus Information" << endl;
        cout << busNumber << "-" << transitName << "-" << sourceRoute << "|" << destinationRoute << "$" << fareAmount << endl;
    }
};

struct PassangerInfo{
    int passID;
    string name;
};

union DriverInfo{
    double driverID;
    int licenseNumber;
    // string driverName; //throws error because of non trivial data type(string). Need to manage constructor and destructor manually
};

int main()
{
    int iVal = 5.1;
    cout << "Int value is: "<< iVal <<"\t" << sizeof(iVal) << endl;
    
    float fVal = 2.1;
    cout << "Float value is: "<< fVal <<"\t" << sizeof(fVal) <<endl;
    
    char cVal = 'p';
    cout << "Char value is: "<< cVal <<"\t" << sizeof(cVal) <<endl;
    
    bool bVal = 0.0001;
    cout << "Bool value is: "<< bVal <<"\t" << sizeof(bVal) <<endl;
    
    string sVal = "Adhithyan";
    cout << "String value is: "<< sVal <<"\t" << sizeof(sVal) <<endl;
    
    int aVal[] = {159,5,10,15};
    cout << "Array value is: "<< aVal <<"\t" << sizeof(aVal) <<endl;
    
    BusInfo bus1;
    bus1.print();
    cout << "Class size value is: "<< sizeof(bus1) << endl;
    
    PassangerInfo p1;
    cout << "Struct size value is: "<< sizeof(p1) << endl;
    
    DriverInfo d1;
    cout << "Union size value is: "<< sizeof(d1) << endl;
    
    int *pVal = aVal;
    cout << "Pointer value is: "<< pVal <<"\t" << sizeof(pVal) <<endl;
    
    vector<string> vVal;
    vVal.push_back("Ford");
    vVal.push_back("JLR");
    cout << "Vector 1st value is: "<< vVal.front() <<"\t" << sizeof(vVal) <<endl;
    cout << "Vector last value is: "<< vVal.back() <<"\t" << sizeof(vVal) <<endl;
    
    return 0;
}
