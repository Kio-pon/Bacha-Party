#include <iostream>


class LinkedList {
    private:
        struct Node {
            int data;
            Node *next;
            Node() : data(0), next(nullptr) {}
            Node(int val) : data(val), next(nullptr) {}
            Node(int d, Node *n) : data(d), next(n) {}
        };
        Node *head;
        Node *tail;
    public:
        LinkedList() : head(nullptr), tail(nullptr) {}

        void addToFront(int value) {
            Node *newNode = new Node(value);
            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            } else {
                newNode->next = head;
                head = newNode;
            }
        }

        void removeFromFront() {
            if (head == nullptr) {
                std::cout << "List is empty. Cannot remove." << std::endl;
                return;
            }
            Node *temp = head;
            head = head->next;
            delete temp;
            temp = nullptr;
            if (head == nullptr) {
                tail = nullptr; // List became empty
            }
        }

        void removeFromRear() {
            if (head == nullptr) {
                std::cout << "List is empty. Cannot remove." << std::endl;
                return;
            }
            if (head == tail) { // Only one element
                delete head;
                head = nullptr;
                tail = nullptr;
                return;
            }
            Node *current = head;
            while (current->next != tail) {
                current = current->next;
            }
            delete tail;
            tail = current;
            tail->next = nullptr;
        }

        void printList() {
            // Starting from the head of the list
            Node *current = head;
            if (current == nullptr) {
                std::cout << "List is empty." << std::endl;
                return;
            }
            while (current != nullptr) {
                std::cout << current->data << " -> ";
                current = current->next;
            }
            std::cout << "NULL" << std::endl;
        }
};

int main() {
    LinkedList l;
    l.removeFromRear();
    l.addToFront(50);
    l.addToFront(51);
    l.addToFront(52);
    l.printList();
    l.removeFromRear();
    l.printList();
    l.removeFromRear();
    l.printList();
    l.removeFromRear();
    l.printList();
    return 0;
}
