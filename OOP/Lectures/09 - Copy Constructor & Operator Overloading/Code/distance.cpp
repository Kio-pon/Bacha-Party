#include <iostream>

using namespace std;

class Distance //English Distance class
{
    private:
        int feet;
        float inches;
        int dynarr[5];
    public:
    //constructor (no args)
    Distance() : feet(0), inches(0.0)
    { }
    //Note: no one-arg constructor
    //constructor (two args)
    Distance(int ft, float in) : feet(ft), inches(in)
    {   //dynarr = new int[5];
        dynarr[0] = ft;
        dynarr[1] = ft + 1;
        dynarr[2] = ft + 2;
        dynarr[3] = ft + 3;
        dynarr[4] = ft + 4;
    }
    void getdist() //get length from user
    {
        cout << "\nEnter feet: "; cin >> feet;
        cout << "Enter inches: "; cin >> inches;    
    }
    void showdist() //display distance
    { cout << feet << "\'-" << inches << "\""; }
    void setfeet(int newfeet) {
        feet = newfeet;
    }
    void setinches(float newinches) {
        inches = newinches;
    }
    void printarray() {
        cout << "\nArray is " << endl;
        for(int i = 0; i < 5; i++) 
            cout << dynarr[i] << " ";
        cout << endl;
    }

    void modifyarray() {
        for(int i = 0; i < 5; i++) 
            dynarr[i] = dynarr[i] + 1;
    }
};
////////////////////////////////////////////////////////////////
int main()
{
    Distance dist1(11, 6.25); //two-arg constructor
    Distance dist2(dist1); //one-arg constructor
    Distance dist3 = dist1; //also one-arg constructor

    dist2.setfeet(10);
    dist2.setinches(5.25);

    dist1.setfeet(12);
    dist1.setinches(4.35);

    //display all lengths
    cout << "\ndist1 = "; dist1.showdist();
    cout << "\ndist2 = "; dist2.showdist();
    cout << "\ndist3 = "; dist3.showdist();

    dist1.printarray();
    dist2.printarray();
    dist3.printarray();

    cout << "Now changing dynamic array for dist1 only" << endl;
    dist1.modifyarray();

    cout << "Now reprinting the array for all objects" << endl;
    dist1.printarray();
    dist2.printarray();
    dist3.printarray();

    cout << endl;
    return 0;
}