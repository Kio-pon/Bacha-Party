
#include<iostream>
using namespace std;
class Circle 
{
    public:
        double radius;
        Circle(double rr=0):radius(rr){}
        double area()
        {
            return 3.14 * radius * radius;
        }  
        friend ostream& operator << (ostream& o , Circle& c)
        {
            o << "Circle with radius " << c.radius << " has area = " << c.area() << endl;
            return o; 
        }  

};


template <typename Q>
class Stack
{              static int count;  
    public:
               static int getCount()
                {return count;}
             int topIndex , size;    Q* p;
            Stack(int len): size(len),topIndex(-1) , p(new Q[size])
            {count++;         }
            
            void push(Q value)
            { p[++topIndex] = value;}

            void showStack()
            {
                for (int i = 0 ;i < size ; i++)
                    cout << p[i] << " " ;
                cout << endl;
            }

};
template <typename Q>
int Stack<Q>::count = 0;
int main()
{
    Stack<int> myIntStack(2); //1
    myIntStack.push(2);
    myIntStack.push(22);
    
    Stack<int> myIntStack2(4); //2
    myIntStack.push(2);
    myIntStack.push(22);
     myIntStack.push(33);
    myIntStack.push(232);

    Stack<string> myStrStack(3); //1
    myStrStack.push("OOP");
    myStrStack.push("DLD");
    myStrStack.push("DM");

    Circle c1(3),c2(4),c3(6),c4(1);

    Stack<Circle> myCircleStack(4); //3
      Stack<Circle> myCircleStack2(7); //3
        Stack<Circle> myCircleStack3(3); //3

    myCircleStack.push(c1);
    myCircleStack.push(c2);
    myCircleStack.push(c3);
    myCircleStack.push(c4);


    myIntStack.showStack();
    myStrStack.showStack();
    myCircleStack.showStack();

    cout << "Total Int Stacks : "<< Stack<int>::getCount()<< endl;
    cout << "Total String Stacks : "<< myStrStack.getCount()<< endl;
    cout << "Total Circle Stacks : "<< Stack<Circle>::getCount()<< endl;


    return 0;
}

