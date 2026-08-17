#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct Node{
    int data;
    Node* next;

    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node* ptr) : data(x), next(ptr) {}
};

typedef Node* Nptr;

class LinkedList{
    public:
        // Constructors
        LinkedList();
        LinkedList(Nptr);
        LinkedList(Nptr, Nptr);
        LinkedList(const LinkedList&); // not implemented 
        LinkedList& operator=(const LinkedList&); // not implemented
        // Destructors
        ~LinkedList();
        // Methods
        void printList() const;
        int len() const; // we can just add {return count;} at the end since we are keeping proper track of count
        void addTop(int);
        void addEnd(int);
        void popTop();
        void popEnd();
        int find(int) const;
        void pop(int);

    private:
        Node* head;
        Node* tail;
        unsigned int count = 0;
};

#endif