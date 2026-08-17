#include "linkedlist.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList() : head(nullptr), tail(nullptr) {}
LinkedList::LinkedList(Nptr h) : head(h), tail(h) {}
LinkedList::LinkedList(Nptr h, Nptr t) : head(h), tail(t) {}

LinkedList::LinkedList(const LinkedList& other) : head(nullptr), tail(nullptr), count(0) {
    Nptr current = other.head;
    while (current) {
        addEnd(current->data);
        current = current->next;
    }
}

LinkedList& LinkedList::operator=(const LinkedList& other) {
    if (this == &other) return *this;  // self-assignment guard

    // Clear current list
    while (head != nullptr) {
        Nptr temp = head;
        head = head->next;
        delete temp;
    }
    head = tail = nullptr;
    count = 0;

    // Copy from other
    Nptr current = other.head;
    while (current) {
        addEnd(current->data);
        current = current->next;
    }
    return *this;
}


LinkedList::~LinkedList(){
    while (head) {
        Nptr temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
    count = 0;
}

void LinkedList::printList() const{
    Nptr current = head;
    while(current != nullptr){
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
    return;
}

int LinkedList::len() const{
    unsigned int temp = 0;
    Nptr current = head;

    while(current != nullptr){
        temp++;
        current = current->next;
    }
    return temp;

    // return count;
}

void LinkedList::addTop(int value){
    Nptr node = new Node(value);
    if(head == nullptr){
        head = tail = node;
    }
    else{
        node->next = head;
        head = node;
    }
    count++;
    return;
}

void LinkedList::addEnd(int value){
    Nptr node = new Node(value);
    if(head == nullptr){
        head = tail = node;
    }
    else{
        tail->next = node;
        tail = node;
    }
    count++;
    return;
}

void LinkedList::popTop(){
    if(head == nullptr) return;
    else{
        Nptr temp = head;
        head = head->next;
        delete temp;
        if(head == nullptr) tail = nullptr;
        count--;
        return;
    }
}

void LinkedList::popEnd(){
    if(head == nullptr) return;
    if(head == tail){
        delete head;
        head = tail = nullptr;
        count--;
        return;
    }
    
    Node* temp = head;
    while (temp->next != tail) {
        temp = temp->next;
    }
    delete tail;
    tail = temp;
    tail->next = nullptr;
    count--;
    return;
}

int LinkedList::find(int value) const{
    if(head==nullptr) return -1;
    Nptr current = head;
    int index = 0;
    while(current != nullptr){
        if(current->data == value) return index;
        current = current->next;
        index++;
    }
    return -1;
}

void LinkedList::pop(int value) {
    if (!head) return;

    // Case 1: value is at head
    if (head->data == value) {
        Nptr temp = head;
        head = head->next;
        if (temp == tail) tail = nullptr; // if it was the only node
        delete temp;
        count--;
        return;
    }

    // Case 2: search in the middle or end
    Nptr current = head;
    while (current->next && current->next->data != value) {
        current = current->next;
    }

    if (!current->next) return; // not found

    Nptr temp = current->next;
    current->next = temp->next;

    if (temp == tail) tail = current; // update tail if needed

    delete temp;
    count--;
    return;
}