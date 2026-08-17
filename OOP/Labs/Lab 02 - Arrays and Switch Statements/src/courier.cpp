#include <iostream>
#include <iomanip>
using namespace std;

// Exercise 2.4: Courier Company Price Analysis using Simulated 2-D Arrays [25 Points]
// Given price tables for three services, look up the price for the
// requested service+cargo category and report average/max/min.

int main()
{

    int northHeights[9] = {500, 900, 1600, 300, 600, 1100, 200, 450, 800};

    int centralPlains[9] = {
        550, 950, 1700, 320, 620, 1150, 220, 470, 850};

    int southernCoastal[9] = {600, 1000, 1800, 350, 650, 1200, 250, 500, 900};

    char service;
    int cargo;

    cout << "Service: ";
    cin >> service;
    cout << "Cargo: ";
    cin >> cargo;

    int serviceRow;
    // TODO: switch on service ('U'/'N'/'E') to set serviceRow (0/1/2),
    // print "Invalid service type!" and return 1 on bad input
    switch (service)
    {
    case 'U':
        break;
    case 'N':
        break;
    case 'E':
        break;
    default:
        cout << "Invalid service type!" << endl;
        return 1;
    }

    // TODO: validate cargo is in [1,3], compute cargoCol, print
    // "Invalid cargo category!" and return 1 on bad input

    // TODO: compute the flattened index into the price arrays from
    // serviceRow and cargoCol, and look up price1/price2/price3

    // TODO: compute average, maximum and minimum of the three prices

    cout << "Category: ";
    switch (service)
    {
    case 'U':
        cout << "Urgent Service";
        break;
    case 'N':
        cout << "Normal Service";
        break;
    case 'E':
        cout << "Economy Service";
        break;
    }
    cout << " , ";
    switch (cargo)
    {
    case 1:
        cout << "Documents";
        break;
    case 2:
        cout << "Parcel < 5kg";
        break;
    case 3:
        cout << "Parcel >= 5kg";
        break;
    }
    cout << endl;

    // TODO: print Prices / Average Price / Maximum Price / Minimum Price

    return 0;
}
