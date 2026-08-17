#include <iostream> 
#include <string>
using namespace std;

class Book
{
    private:
        string Name;
        string Author;
        int Volume;
        int PublicationYear;
        double Price;

    public:
        Book(){}

        Book(string N, string A, int V, int Y, double P)
        {
            Name = N;
            Author = A;
            Volume = V;
            PublicationYear = Y;
            Price = P;
        };

        string displayBook()
        {
            return Name + " vol. " + to_string(Volume) + " by " + Author + ", " + to_string(PublicationYear);
        }

        string getName()
        {
            return Name;
        }
        string getAuthor()
        {
            return Author;
        }
        int getVolume()
        {
            return Volume;
        }
        int getPublicationYear()
        {
            return PublicationYear;
        }
        double getPrice()
        {
            return Price;
        }

        // void setName(string N)
        // {
        //     Name = N;
        // }
        // void setAuthor(string A)
        // {
        //     Author = A;
        // }
        // void setVolume(int V)
        // {
        //     Volume = V;
        // }
        // void getPublicationYear(int Y)
        // {
        //     PublicationYear = Y;
        // }
        // void getPrice(double P)
        // {
        //     Price = P;
        // }
};

class BookShelf
{
    private:
        int space;
        int numberOfBooks;
        Book *books;

    public:
        BookShelf(int s)
        {
            space = s;
            books =  new Book[space];
            numberOfBooks = 0;
        }

        string AddBook(Book B)
        {
            if (space == numberOfBooks)
            {
                return "There is no more space on the book shelf!\n";
            }
            else
            {
                books[numberOfBooks] = B;
                numberOfBooks ++;

                return B.displayBook() + " added to the book shelf\n";
            }
        }

        string ShowCollection()
        {
            string out = "";
            for (int i = 0; i < numberOfBooks; i++)
            {
                out += books[i].displayBook() + "\n";
            }
            return out;
        }

        double worth()
        {
            double amount = 0.0;
            for (int i = 0; i < numberOfBooks; i++)
            {
                amount += books[i].getPrice();
            }
            return amount;
        }


        
};
