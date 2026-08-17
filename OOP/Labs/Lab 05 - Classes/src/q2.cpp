#include <iostream>
using namespace std;

// Q2. Stack Class (using Arrays): MyStack must not be default-constructible
// without a size, and must avoid memory leaks (see destructor).
class MyStack
{
private:
    int size, *ptr = nullptr, last_index = -1;

public:
    MyStack(int num)
    {
        // TODO: store size and allocate the backing array
    }
    bool isempty()
    {
        // TODO: return true if the stack has no elements
        return false;
    }
    bool isfull()
    {
        // TODO: return true if the stack is at capacity
        return false;
    }
    void push(int num1)
    {
        // TODO: push num1 onto the stack, printing "Stack is full." if isfull()
    }
    int top()
    {
        // TODO: return the top element without removing it
        return -1;
    }

    int pop()
    {
        // TODO: remove and return the top element; print "The stack is empty"
        // and return -1 if isempty()
        return -1;
    }

    void display()
    {
        for (int i = 0; i < last_index; i++)
        {
            cout << ptr[i] << " , ";
        }
        cout << ptr[last_index] << endl;
    }
    ~MyStack()
    {
        // TODO: free the backing array
    }
};

int main()
{
    MyStack S1(4);

    S1.pop();

    S1.push(1);
    S1.push(5);
    S1.push(3);
    S1.push(4);
    S1.display();
    S1.push(10);
    S1.display();
    cout << S1.pop() << endl;
    cout << S1.top() << endl;
    cout << (S1.isempty() ? "true" : "false") << endl;
    S1.display();
    return 0;
}
