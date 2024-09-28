#include "LinkedList.h"
#include <iostream>
using namespace std;

int main() {
    LinkedList list;
    list.insertAtBeginning(10);
    list.insertAtBeginning(20);
    list.insertAtEnd(30);
    list.insertAtPosition(2, 25);

    cout << "Linked List: ";
    list.display();

    cout << "Searching for 25: " << (list.search(25) ? "Found" : "Not Found") << endl;

    list.deleteByValue(20);
    cout << "After deleting 20: ";
    list.display();

    return 0;
}
