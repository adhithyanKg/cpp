/* Library Management System */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class LibraryItem{
    protected:
        string title;
        string author;
        int itemId;
    private:
        bool borrowed;
    public:
        LibraryItem(string a, string b, int c) : title(a), author(b), itemId(c), borrowed(false) {}
        void borrowItem(){
            borrowed=true;
        }
        void returnItem(){
            borrowed=false;
        }
        string isAvailable(){
            return borrowed ? "No" : "Yes";
        }
        virtual void displayDetails()
        {
            cout << "Title: " << title << endl;
            cout << "Author: " << author << endl;
            cout << "ItemId: " << itemId << endl;
            cout << "Available status: " << isAvailable() << endl;
        }
        virtual ~LibraryItem()
        {
            cout << "LibraryItem Destructor"<< endl;
        }
};
class Book : public LibraryItem{
    private:
        int pages;
    public:
        Book(string a, string b, int c, int d) : LibraryItem(a,b,c), pages(d){}
        void displayDetails() override
        {
            LibraryItem::displayDetails();
           cout << "Pages: " << pages << endl;
        }
        ~Book()
        {
            cout << "Book Destructor"<< endl;
        }
};
class DVD : public LibraryItem{
    private:
        int duration;
    public:
        DVD(string a, string b, int c, int d) : LibraryItem(a,b,c), duration(d){}
        void displayDetails() override
        {
            LibraryItem::displayDetails();
            cout << "Duration: " << duration << endl;
            if(author == "QPR"){
                cout << "This author has new DVD's, please checkout in section 1:21"<< endl;
            }
        }
        ~DVD()
        {
            cout << "DVD Destructor"<< endl;
        }
};

int main()
{
    vector<LibraryItem*> items; //resizeable array
    items.push_back(new Book("ABC", "XYZ", 1, 92));
    items.push_back(new DVD("EFG", "QPR", 1, 45));
    items.push_back(new DVD("YRT", "KJH", 2, 68));
    items.push_back(new Book("KLM", "FRH", 2, 102));
    
    for(int i=0; i<items.size(); i++)
    {
        items[i]->displayDetails();
        cout << "----------------------------" << endl;
        
    }
    items[1]->borrowItem();
    cout << "After borrowed: " << endl;
    cout << "----------------------------" << endl;
    
    for(int i=0; i<items.size(); i++)
    {
        items[i]->displayDetails();
        cout << "----------------------------" << endl;
    }
    
    for (int i = 0; i < items.size(); i++) {
        delete items[i];
    }
    
    return 0;
}
