#include <iostream>
#include <cstring>
using namespace std;

class Node {
public:
    char name[50];
    Node* next;

    Node(const char* friendName) {
        strcpy(name, friendName);
        next = nullptr;
    }
};

class FriendList {
    Node* head;

public:
    FriendList() {
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
    void addAtBeg(const char* friendName) {
        Node* newNode = new Node(friendName);
        newNode->next = head;
        head = newNode;
    }

    // Function to append a node at the end
    void append(const char* friendName) {
        Node* newNode = new Node(friendName);
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

    // Function to display the linked list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->name << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Function to display detailed information
    void displayMORE() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << "Address: " << temp << ", Name: " << temp->name << ", Next: " << temp->next << endl;
            temp = temp->next;
        }
    }
};

int main() {
    FriendList friends;

    // Adding friends
    friends.addAtBeg("Alice");
    friends.append("Bob");
    friends.append("Charlie");

    // Display list
    cout << "Friend List: ";
    friends.display();

    // Detailed display
    cout << "\nDetailed Display:" << endl;
    friends.displayMORE();

    // Length of the list
    cout << "\nLength of the friend list: " << friends.getLength() << endl;

    return 0;
}
