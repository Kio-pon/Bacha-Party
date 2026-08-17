#include <iostream>
#include <string>
using namespace std;

// Exercise: publication base class with book/tape derived classes.
// publication stores title (string) and price (float).
class publication
{
protected:
    string title;
    float price;

public:
    void getdata()
    {
        // TODO: read title (whole line) and price
    }
    void putdata() const
    {
        cout << "Publication title: " << title << endl;
        cout << "Publication price: " << price << endl;
    }
};

class book : public publication
{
private:
    int page_count;

public:
    void getdata()
    {
        // TODO: call publication::getdata() then read page_count
    }
    void putdata() const
    {
        // TODO: call publication::putdata() then print page_count
    }
};

class tape : public publication
{
private:
    float playing_time;

public:
    void getdata()
    {
        // TODO: call publication::getdata() then read playing_time
    }
    void putdata() const
    {
        // TODO: call publication::putdata() then print playing_time
    }
};

int main()
{
    book b;
    tape t;
    b.getdata();
    cin.ignore();
    t.getdata();
    b.putdata();
    t.putdata();
}
