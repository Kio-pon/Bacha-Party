#include <cstring>
using namespace std;


void reverse(char *inp, int n)
{
    for(int i = 0; i < n/2; i++)
    {   
        char temp = inp[n-i-1];
        inp[n-i-1] = inp[i];
        inp[i] = temp;
    }

}

// int main()
// {
//     int n;
//     cin >> n;

//     char *str = new char[n];
//     cin >> str;

//     cout << str << endl;

//     decode(str, n);

//     cout << str;

//     return 0;
// }