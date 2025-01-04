/* Library Management System */

#include <iostream>
#include <string>

#define MAX_ITEM 3

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
            std::cout << "Title: " << title << std::endl;
            std::cout << "Author: " << author << std::endl;
            std::cout << "ItemId: " << itemId << std::endl;
            std::cout << "Available status: " << isAvailable() << std::endl;
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
            std::cout << "Pages: " << pages << std::endl;
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
            std::cout << "Duration: " << duration << std::endl;
            if(author == "QPR"){
                 std::cout << "This author has new DVD's, please checkout in section 1:21"<< std::endl;
            }
        }
};

int main()
{
    LibraryItem* items[MAX_ITEM];
    items[0] = new Book("ABC", "XYZ", 1, 92);
    items[1] = new DVD("EFG", "QPR", 1, 45);
    items[2] = new DVD("YRT", "KJH", 2, 68);
    
    for(int i=0; i<MAX_ITEM; i++)
    {
        items[i]->displayDetails();
        std::cout << "----------------------------" << std::endl;
        
    }
    items[1]->borrowItem();
    std::cout << "After borrowed: " << std::endl;
    std::cout << "----------------------------" << std::endl;
    
    for(int i=0; i<MAX_ITEM; i++)
    {
        items[i]->displayDetails();
        std::cout << "----------------------------" << std::endl;
    }
    
    for (int i = 0; i < MAX_ITEM; i++) {
        delete items[i];
    }
    
    return 0; 
}
