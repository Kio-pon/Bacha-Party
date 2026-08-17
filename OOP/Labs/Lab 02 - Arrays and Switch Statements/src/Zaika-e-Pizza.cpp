#include <iostream>
using namespace std;

// Exercise 2.2: Zaika-e-Pizza Ordering System [25 Points]
// Use switch statements to price two pizzas (size + flavour) and apply
// the correct day-of-week deal to the final bill.

int sizee(char size)
{
    int base = -1;
    // TODO: switch on size ('s'/'m'/'l'), print the size label and set base price
    switch (size)
    {
    case 's':
        break;
    case 'm':
        break;
    case 'l':
        break;
    }
    return base;
}

int flavour(char fav)
{
    int extra = -1;
    // TODO: switch on fav ('p'/'v'/'c'/'b'/'a'), print the flavour label and set extra price
    switch (fav)
    {
    case 'p':
        break;
    case 'v':
        break;
    case 'c':
        break;
    case 'b':
        break;
    case 'a':
        break;
    }
    return extra;
}

int inputchecker(char type, char val)
{
    // TODO: validate that `val` is a legal flavour ('f'/'F') or size ('s'/'S') character
    return 0;
}

int main()
{
    char size1, fav1, size2, fav2;
    int prize1, prize2, day;
    float total;

    cout << "- Welcome to Zaika-e-Pizza - " << endl;

    // TODO: prompt for day (1-7), validating with inputchecker/range check

    // TODO: prompt for first pizza flavour and size (validated with inputchecker)

    // TODO: prompt for second pizza flavour and size (validated with inputchecker)

    cout << "You ordered:" << endl;
    // TODO: compute prize1 and prize2 using sizee() + flavour(), print each

    // TODO: compute total = prize1 + prize2, then apply the deal for the
    // selected day (Monday..Sunday) per the manual's rules, and print the
    // final bill

    return 0;
}
