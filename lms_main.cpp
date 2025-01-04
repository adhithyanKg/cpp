/* Library Management System */

#include <iostream>
#include <string>
#include <vector>
#include <memory>

#define SPECIAL_AUTHOR_CONDITION "QPR"

using namespace std;

class LibraryItem{
    protected:
        string title;
        string author;
        int itemId;
        bool isborrowed() const {
            return borrowed;
        }
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
        string isAvailable() const {
            return borrowed ? "No" : "Yes";
        }
        virtual void displayDetails() const
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
        void displayDetails() const override
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
        void displayDetails() const override 
        {
            LibraryItem::displayDetails();
            cout << "Duration: " << duration << endl;
            if(isborrowed()){
                cout << "Must be returned in 7 days"<< endl;
                if(author == SPECIAL_AUTHOR_CONDITION){
                    cout << "This author has new DVD's, please checkout in section 1:21"<< endl;
                }
            }
        }
        ~DVD()
        {
            cout << "DVD Destructor"<< endl;
        }
};
void displayItems(const vector<unique_ptr<LibraryItem>>& items)
{
    for(auto& item: items)
    {
        item->displayDetails();
        cout << "----------------------------" << endl;
        
    }
}
int main()
{
    vector<unique_ptr<LibraryItem>> items;
    
    items.push_back(make_unique<Book>("ABC", "XYZ", 1, 92));
    items.push_back(make_unique<DVD>("EFG", "QPR", 1, 45));
    items.push_back(make_unique<DVD>("YRT", "KJH", 2, 68));
    items.push_back(make_unique<Book>("KLM", "FRH", 2, 102));
    
    displayItems(items);
    
    items[1]->borrowItem();
    items[2]->borrowItem();
    cout << "After borrowed: " << endl;
    cout << "----------------------------" << endl;
    
    displayItems(items);
    return 0;
}
