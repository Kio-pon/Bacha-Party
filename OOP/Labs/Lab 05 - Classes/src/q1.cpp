#include <iostream>
using namespace std;

// Q1. TollBooth class.
// Track how many cars pass ('p' = paying car, 'n' = non-paying car, 'q' = quit)
// and how much toll (Rs. 50/paying car) has been collected.
class TollBooth
{
private:
    unsigned int car, amount;

public:
    TollBooth()
    {
        // TODO: initialize car and amount to 0
    }

    void payingCar()
    {
        // TODO: increment car count and add 50 to amount
    }
    void nopayCar()
    {
        // TODO: increment car count only
    }
    void display()
    {
        cout << "Total Cars Passed : " << car << endl;
        cout << "Total Toll collected : " << amount << endl;
    }
};

int main()
{
    TollBooth gang;
    char check = 't';
    while (check != 'q')
    {
        cin >> check;
        if (check == 'p')
            gang.payingCar();
        else if (check == 'n')
            gang.nopayCar();
    }
    gang.display();
    return 0;
}
