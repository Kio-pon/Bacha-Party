#include "linkedlist.h"
#include <iostream>
using namespace std;

int main() {
    LinkedList list;

    // Add elements at top
    list.addTop(10);
    list.addTop(20);
    list.addTop(30);
    cout << "After adding at top: ";
    list.printList(); // 30 20 10

    // Add elements at end
    list.addEnd(40);
    list.addEnd(50);
    cout << "After adding at end: ";
    list.printList(); // 30 20 10 40 50

    // Length
    cout << "Length of list: " << list.len() << endl; // 5

    // Find elements
    cout << "Index of 20: " << list.find(20) << endl; // 1
    cout << "Index of 100 (not found): " << list.find(100) << endl; // -1

    // Pop top
    list.popTop();
    cout << "After popTop: ";
    list.printList(); // 20 10 40 50

    // Pop end
    list.popEnd();
    cout << "After popEnd: ";
    list.printList(); // 20 10 40

    // Pop specific value
    list.pop(10);
    cout << "After popping 10: ";
    list.printList(); // 20 40

    // Pop head value
    list.pop(20);
    cout << "After popping 20: ";
    list.printList(); // 40

    // Pop tail value
    list.pop(40);
    cout << "After popping 40 (list should be empty): ";
    list.printList(); // empty

    cout << "Final length: " << list.len() << endl; // 0

    return 0;
}
