#include <iostream>
#include <cstring>
using namespace std;

struct Contact {
    char name[50];
    long long phoneNumber;
};

class Node {
public:
    Contact contact;
    Node* next;

    Node(const char* contactName, long long contactNumber) {
        strcpy(contact.name, contactName);
        contact.phoneNumber = contactNumber;
        next = nullptr;
    }
};

class ContactList {
    Node* head;

public:
    ContactList() {
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

    // Function to add a contact at the beginning
    void addAtBeg(const char* contactName, long long contactNumber) {
        Node* newNode = new Node(contactName, contactNumber);
        newNode->next = head;
        head = newNode;
    }

    // Function to append a contact at the end
    void append(const char* contactName, long long contactNumber) {
        Node* newNode = new Node(contactName, contactNumber);
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

    // Function to display the contacts in the list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << "Name: " << temp->contact.name << ", Phone: " << temp->contact.phoneNumber << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Function to display detailed information
    void displayMORE() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << "Address: " << temp << ", Name: " << temp->contact.name << ", Phone: " << temp->contact.phoneNumber << ", Next: " << temp->next << endl;
            temp = temp->next;
        }
    }
};

int main() {
    ContactList contacts;

    // Adding contacts
    contacts.addAtBeg("Alice", 9876543210);
    contacts.append("Bob", 1234567890);
    contacts.append("Charlie", 5555555555);

    // Display contacts
    cout << "Contact List: ";
    contacts.display();

    // Detailed display
    cout << "\nDetailed Display:" << endl;
    contacts.displayMORE();

    // Length of the contact list
    cout << "\nLength of the contact list: " << contacts.getLength() << endl;

    return 0;
}
