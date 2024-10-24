#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class OddEvenList {
    Node* head;
    Node* oddTail;
    Node* evenHead;

public:
    OddEvenList() {
        head = nullptr;
        oddTail = nullptr;
        evenHead = nullptr;
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

    // Function to add an integer
    void append(int val) {
        Node* newNode = new Node(val);
        if (val % 2 != 0) { // Odd
            if (oddTail == nullptr) {
                head = newNode;
                oddTail = newNode;
            } else {
                oddTail->next = newNode;
                oddTail = newNode;
            }
        } else { // Even
            if (evenHead == nullptr) {
                evenHead = newNode;
            } else {
                Node* temp = evenHead;
                while (temp->next != nullptr) {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }
    }

    // Function to display the linked list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        temp = evenHead;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }

    // Function to display detailed information
    void displayMORE() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << "Address: " << temp << ", Value: " << temp->data << ", Next: " << temp->next << endl;
            temp = temp->next;
        }

        temp = evenHead;
        while (temp != nullptr) {
            cout << "Address: " << temp << ", Value: " << temp->data << ", Next: " << temp->next << endl;
            temp = temp->next;
        }
    }
};

int main() {
    OddEvenList list;

    // Adding integers to the list
    list.append(1);
    list.append(4);
    list.append(7);
    list.append(8);
    list.append(9);

    // Display list
    cout << "Odd-Even List: ";
    list.display();

    // Detailed display
    cout << "\nDetailed Display:" << endl;
    list.displayMORE();

    // Length of the list
    cout << "\nLength of the odd-even list: " << list.getLength() << endl;

    return 0;
}
