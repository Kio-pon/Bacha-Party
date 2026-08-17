#include<iostream>
#include <cctype> // Required for toupper()
#include <cstring> // Required for strlen()
using namespace std;

 // Iterate through the array and convert each character
 void convertToUpper(char a[])
 {
    for (int i = 0; i < strlen(a); ++i) {
        a[i] = toupper(a[i]);
    }
}
void printAllNames(char n[][100] , int len){
     for (int i = 0 ; i < 5 ; i++)
    {
        convertToUpper(n[i]);
        cout << n[i] << endl;

    }
    
}
int main()
{
    int size;
    cout << "Enter number of names : " ;
    cin >> size;
    char names[size][100];

    //using pointer notation
    //input all names from user
    cin.ignore();
    for (int i = 0 ; i < size ; i++)
    {   
        cin.getline(names[i],100);
    }

    //print all names in Capital case
    printAllNames(names , size);// passing the address of names array

    return 0;

}