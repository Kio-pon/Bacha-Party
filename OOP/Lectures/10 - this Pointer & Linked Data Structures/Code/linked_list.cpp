#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Linked List class
class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void addElementToRear(int value){
        Node* newNode = new Node(value);
        if (head == nullptr){
            head = tail = newNode;
        } else{
            tail -> next = newNode;
            tail = newNode;
        }

    }

    // Add to front
    void addElementToFront(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    // Print the list
    void printList() {
        Node* current = head;
        cout << "List: ";
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }

};

int main(){

    LinkedList list;

    cout <<" Adding elements to the front and back, starting with front" <<endl;

    list.addElementToFront(10); // head & tail = 10

    // How do you initialize the values of a Linkedlist class using a cnstructor?

    list.printList();
    list.addElementToFront(20); // head = 20, tail = 10

    list.printList();

    list.addElementToFront(30); // head = 30, tail = 10

    list.printList(); // 30 -> 20 -> 10

    cout << "Adding to Rear" <<endl;

    list.addElementToRear(40); //

    list.printList(); // 30 -> 20 -> 10 -> 40

    list.addElementToRear(50);
    list.printList(); // 30 -> 20 -> 10 -> 40 -> 50
}

