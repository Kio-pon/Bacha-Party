#include<iostream>
using namespace std;

template <typename T>
int countElements(T arr[], int size)
{
    int counter=0;
    for (int k =0; k< size ; k++)
    {
        if(arr[k] != 0)
            counter++;
       
    }
     return counter;

}


int main()
{

    int marks[5] = {3,5,2,1,0};
    //char* name = "Hello";
    double temp[8] = {3.5,2.6,8.8 ,0,0,0,0,0};

    cout << countElements<int>(marks , 5) << endl;
     cout << countElements<double>(temp , 8) << endl;

  

    return 0;
}