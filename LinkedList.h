#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class Node {
public:
    int data;
    Node* next;

    Node(int val);
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList();
    ~LinkedList();

    void insertAtBeginning(int val);
    void insertAtEnd(int val);
    void insertAtPosition(int pos, int val);
    void deleteByValue(int val);
    bool search(int val);
    void display();
};

#endif
