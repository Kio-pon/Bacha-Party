#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// LinkedList class
class NetRunnerList {
private:
    Node* head;

public:
    // Constructor
    NetRunnerList() {
        head = nullptr;
    }

    // Insert `value` at the front of the list
    void Insert(int value) {
        // TODO: create a new node and make it the new head
    }

    // Print function: displays the list
    void Print() {
        Node* current = head;
        cout << "Linked List: ";
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }

};


int main() {

    // Output: List: 4 -> 22 -> 2 -> 11 -> 19 -> 7 -> 5 -> NULL
    {
    NetRunnerList list;
    list.Insert(5);
    list.Insert(2);
    list.Insert(7);
    list.Insert(19);
    list.Insert(22);
    list.Insert(4);
    list.Insert(11);
    list.Print();
    }

    // Output: List: 16 -> 40 -> 8 -> 3 -> 11
    {
    NetRunnerList list;
    list.Insert(8);
    list.Insert(11);
    list.Insert(3);
    list.Insert(40);
    list.Insert(16);
    list.Print();
    }


    return 0;
}
