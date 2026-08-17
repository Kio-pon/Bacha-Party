#include <iostream>

using namespace std;

// Node class

class Node
{

public:
    int data; // Data to store

    Node *next; // Pointer to the next node

    Node(int value) : data(value), next(nullptr) {} // Constructor
};

// LinkedList class

class LinkedList
{

private:
    Node *head; // Pointer to the first node

public:
    LinkedList() : head(nullptr) {} // Constructor

    // Add node to the beginning

    void addToBeginning(int value)
    {

        Node *newNode = new Node(value);

        newNode->next = head;

        head = newNode;
    }

    // Add node to the end

    void addToEnd(int value)
    {

        Node *newNode = new Node(value);

        if (!head)
        {

            head = newNode;
        }
        else
        {

            Node *temp = head;

            while (temp->next != nullptr)
            {

                temp = temp->next;
            }

            temp->next = newNode;
        }
    }

    // Delete node from the beginning

    void deleteFromBeginning()
    {

        if (!head)
        {

            cout << "List is empty, nothing to delete.\n";

            return;
        }

        Node *temp = head;

        head = head->next;

        delete temp;
    }

    // Delete node from the end

    void deleteFromEnd()
    {

        if (!head)
        {

            cout << "List is empty, nothing to delete.\n";

            return;
        }

        if (!head->next)
        { // Only one element

            delete head;

            head = nullptr;
        }
        else
        {

            Node *temp = head;

            while (temp->next->next != nullptr)
            {

                temp = temp->next;
            }

            delete temp->next;

            temp->next = nullptr;
        }
    }

    // Display the linked list

    void display()
    {

        if (!head)
        {

            cout << "List is empty.\n";

            return;
        }

        Node *temp = head;

        while (temp != nullptr)
        {

            cout << temp->data << " -> ";

            temp = temp->next;
        }

        cout << "null\n";
    }
};

// Main function for testing

int main()
{

    LinkedList list;

    // Test adding to the beginning

    cout << "Adding 10 and 20 to the beginning of the list:\n";

    list.addToBeginning(10);

    list.addToBeginning(20);

    list.display();

    // Test adding to the end

    cout << "\nAdding 30 and 40 to the end of the list:\n";

    list.addToEnd(30);

    list.addToEnd(40);

    list.display();

    // Test deleting from the beginning

    cout << "\nDeleting from the beginning:\n";

    list.deleteFromBeginning();

    list.display();

    // Test deleting from the end

    cout << "\nDeleting from the end:\n";

    list.deleteFromEnd();

    list.display();

    return 0;}