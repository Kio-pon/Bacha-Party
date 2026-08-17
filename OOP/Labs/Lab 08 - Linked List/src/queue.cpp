#include <iostream>
using namespace std;

// Question 2 - Queue Implementation using Linked List (FIFO)
// Node class
class Node
{
public:
    int data;
    Node *next;

    Node(int value) : data(value), next(nullptr) {}
};

// Queue class
class Queue
{
private:
    Node *front;
    Node *rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    // Function to insert an element at the rear
    void enqueue(int value)
    {
        // TODO: add a new node at the rear of the queue
    }

    // Function to remove an element from the front
    void dequeue()
    {
        // TODO: remove the front node; print "Queue is empty, nothing to
        // dequeue." if isEmpty()
    }

    // Function to print the queue
    void print_queue()
    {
        // TODO: print elements as "a -> b -> ... -> null", or "Queue is
        // empty." if there are none
    }

    // Helper: Check if queue is empty
    bool isEmpty()
    {
        // TODO: return true if the queue has no elements
        return true;
    }
};

// Main function
int main()
{
    Queue q;
    int n, val;

    cout << "Enter number of elements to enqueue: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        q.enqueue(val);
    }

    cout << "Queue after enqueue: ";
    q.print_queue();

    int d;
    cout << "Enter number of elements to dequeue: ";
    cin >> d;
    for (int i = 0; i < d; i++)
    {
        q.dequeue();
    }

    cout << "Queue after dequeue: ";
    q.print_queue();

    return 0;
}
