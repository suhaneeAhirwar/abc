#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* next;

    Node(char data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList {
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Function to get the length of the linked list
    int getLength() {
        int length = 0;
        Node* temp = head;
        while (temp != nullptr) {
            length++;
            temp = temp->next;
        }
        return length;
    }

    // Function to add a node at the beginning
    void addAtBeg(char x) {
        Node* newNode = new Node(x);
        newNode->next = head;
        head = newNode;
    }

    // Function to append a node at the end
    void append(char x) {
        Node* newNode = new Node(x);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Function to add a node at a specific position
    void addAtPOS(char x, int pos) {
        if (pos < 1 || pos > getLength() + 1) {
            cout << "Invalid position!" << endl;
            return;
        }

        if (pos == 1) {
            addAtBeg(x);
            return;
        }

        Node* newNode = new Node(x);
        Node* temp = head;

        for (int i = 1; i < pos - 1; i++) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Function to display the linked list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Function to display detailed information (address, value, and next address)
    void displayMORE() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << "Address: " << temp << ", Value: " << temp->data << ", Next: " << temp->next << endl;
            temp = temp->next;
        }
    }
};

int main() {
    LinkedList list;

    // Adding some elements to the linked list
    list.addAtBeg('A');
    list.append('B');
    list.addAtPOS('C', 2);
    list.append('D');

    // Display the list
    cout << "Linked List: ";
    list.display();

    // Display detailed information
    cout << "\nDetailed Display of Linked List:" << endl;
    list.displayMORE();

    // Display the length of the list
    cout << "\nLength of the linked list: " << list.getLength() << endl;

    return 0;
}
