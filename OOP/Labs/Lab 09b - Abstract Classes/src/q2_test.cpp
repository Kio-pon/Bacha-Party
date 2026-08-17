#include "src/q2_numbers.h"

// You can compile this file to test the Numbers (const corretness) question
// Compile using the following command:
// g++ q2_test.cpp src/q2_numbers.h -o q2
int main(){
    NumWhole n1(33u), n2(44u);
    n1.display(); cout<<","; n2.display(); cout<<endl; //33,44 followed by newline

    // displaying const numbers
    NumWhole const n3(55u), n4(66u);
    n3.display(); cout<<","; n4.display(); cout<<endl; //55,66 followed by newline

    NumWhole n5 = n3 + n4;
    n5.increment(); n5.display(); cout<<endl; //should display 122, followed by a newline

    NumComplex c1(2,0), c2(4,-5);
    c1.display(); c2.display(); cout<<endl; //(2+0i)(4-5i) followed by newline

    NumComplex const c3(2,0), c4(4,-5);
    c3.display(); c4.display(); cout<<endl; //(2+0i)(4-5i) followed by newline

    NumComplex c5 = c3 + c4;
    c5.increment(); c5.display(); cout<<endl; //(y-4i) followed by newline

    NumInterface const * p[10] = {&n1, &n2, &n3, &n4, &n5, &c1, &c2, &c3, &c4, &c5};

    // below display: 33,44,55,66,122,(2+0i),(4-5i),(2+0i),(4-5i),(7-4i),
    for(int i=0; i<10; i++)
    {
        p[i]->display();
        cout<<",";
    }
    cout<<endl;

    return 0;
}