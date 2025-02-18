/* This file contains exception handling mechanism in C++ */
#include <iostream>

using namespace std;

class BankAccount{
    double balance;
    
    public:
    
    BankAccount(double initialBalance = 0)
    {
        if(initialBalance < 0)
        {
            throw runtime_error("Invalid initialBalance");
        }
        else
        {
            balance = initialBalance;
        }
        
    }
    void deposit(double amount)
    {
        if (amount < 0)
            throw runtime_error ("Negative deposit not allowed");
        else
            balance +=amount;
        
    }
    void withdraw(double amount)
    {
        if (amount < 0)
            throw runtime_error ("Negative withdrawal is not allowed");
        else if(amount > balance)
        {
            throw runtime_error ("Insufficient funds");
        }
        else
            balance -=amount;
        
    }
    void const printBalance()
    {
       
        cout << "Balance: " << balance << endl;
    }
};

int main() {
  
    try{
    double initialBalance;
    int option; 
    double amount;
    cout<<"Enter Initial Balance"<<endl;
    cin>>initialBalance;
    BankAccount A1(initialBalance);
    
   
    while(true){
       
        cout << "Enter 1 for deposit, 2 for withdraw, 3 for view balance and 0 for exit" << endl;
        cin >> option;
        
        if(option == 0){
            cout << "Existing, Thank you!" << endl;
            break;
        }
        else if(option == 1)
        {
            cout << "Enter deposit amount" << endl;
            cin >> amount;
            A1.deposit(amount); 
        }
        else if(option == 2)
        {
            cout << "Enter withdraw amount" << endl;
            cin >> amount;
            A1.withdraw(amount);
        }
        else if(option == 3)
            A1.printBalance();
        else
            cout<< "Invalid option" << endl;
    }
    }
    catch(const exception& e)
    {
        cout << e.what() << endl;
    }
    return 0;
}
