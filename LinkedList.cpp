#include "LinkedList.h"
#include <iostream>
using namespace std;

// Constructor for Node
Node::Node(int val) {
    data = val;
    next = nullptr;
}

// Constructor for LinkedList
LinkedList::LinkedList() {
    head = nullptr;
}

// Destructor for LinkedList to clean up memory
LinkedList::~LinkedList() {
    Node* current = head;
    Node* nextNode;
    while (current != nullptr) {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

// Insert a node at the beginning
void LinkedList::insertAtBeginning(int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

// Insert a node at the end
void LinkedList::insertAtEnd(int val) {
    Node* newNode = new Node(val);
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

// Insert a node at a specific position
void LinkedList::insertAtPosition(int pos, int val) {
    if (pos == 1) {
        insertAtBeginning(val);
        return;
    }
    Node* newNode = new Node(val);
    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Position out of range!" << endl;
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete a node by value
void LinkedList::deleteByValue(int val) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }
    if (head->data == val) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != val) {
        temp = temp->next;
    }
    if (temp->next == nullptr) {
        cout << "Value not found!" << endl;
        return;
    }
    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;
}

// Search for a value in the list
bool LinkedList::search(int val) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data == val)
            return true;
        temp = temp->next;
    }
    return false;
}

// Display the linked list
void LinkedList::display() {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
