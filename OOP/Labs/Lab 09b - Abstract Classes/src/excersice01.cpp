#include <iostream>
using namespace std;

class NumInterface
{
public:
    virtual void display() = 0;
    virtual void increment() = 0;
};
int main()
{
    // this is an abstract class which have prue virtual fucntion its ibject can not be maded
    // NumInterface num;
    return 0;
}