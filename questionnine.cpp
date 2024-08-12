#include <iostream>
using namespace std;

// Node class for linked list
class Node {
public:
    int value;
    Node* next;

    Node(int data) {
        value = data;
        next = nullptr;
    }
};

// OddEvenList class for managing the odd-even list
class OddEvenList {
private:
    Node* oddHead;
    Node* evenHead;
    Node* oddTail;
    Node* evenTail;

public:
    OddEvenList() : oddHead(nullptr), evenHead(nullptr), oddTail(nullptr), evenTail(nullptr) {}

    // Add a node to the list based on odd/even value
    void add(int value) {
        Node* newNode = new Node(value);
        if (value % 2 != 0) { // Odd value
            if (oddHead == nullptr) {
                oddHead = newNode;
                oddTail = newNode;
            } else {
                oddTail->next = newNode;
                oddTail = newNode;
            }
        } else { // Even value
            if (evenHead == nullptr) {
                evenHead = newNode;
                evenTail = newNode;
            } else {
                evenTail->next = newNode;
                evenTail = newNode;
            }
        }
    }

    // Display all nodes
    void display() {
        Node* temp = oddHead;
        cout << "Odd elements: ";
        while (temp != nullptr) {
            cout << temp->value << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;

        temp = evenHead;
        cout << "Even elements: ";
        while (temp != nullptr) {
            cout << temp->value << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Display more detailed information
    void displayMore() {
        Node* temp = oddHead;
        cout << "Odd elements detailed info:" << endl;
        while (temp != nullptr) {
            cout << "Address: " << temp;
            cout << ", Value: " << temp->value;
            cout << ", Next Address: " << temp->next << endl;
            temp = temp->next;
        }

        temp = evenHead;
        cout << "Even elements detailed info:" << endl;
        while (temp != nullptr) {
            cout << "Address: " << temp;
            cout << ", Value: " << temp->value;
            cout << ", Next Address: " << temp->next << endl;
            temp = temp->next;
        }
    }

    // Remove the first node from odd list
    void deleteAtStartOdd() {
        if (oddHead == nullptr) {
            cout << "Odd list is empty!" << endl;
            return;
        }
        Node* temp = oddHead;
        oddHead = oddHead->next;
        delete temp;
        if (oddHead == nullptr) {
            oddTail = nullptr;
        }
    }

    // Remove the last node from odd list
    void deleteAtEndOdd() {
        if (oddHead == nullptr) {
            cout << "Odd list is empty!" << endl;
            return;
        }
        if (oddHead->next == nullptr) {
            delete oddHead;
            oddHead = nullptr;
            oddTail = nullptr;
            return;
        }
        Node* secondLast = oddHead;
        while (secondLast->next->next != nullptr) {
            secondLast = secondLast->next;
        }
        Node* temp = secondLast->next;
        secondLast->next = nullptr;
        oddTail = secondLast;
        delete temp;
    }

    // Remove the first node from even list
    void deleteAtStartEven() {
        if (evenHead == nullptr) {
            cout << "Even list is empty!" << endl;
            return;
        }
        Node* temp = evenHead;
        evenHead = evenHead->next;
        delete temp;
        if (evenHead == nullptr) {
            evenTail = nullptr;
        }
    }

    // Remove the last node from even list
    void deleteAtEndEven() {
        if (evenHead == nullptr) {
            cout << "Even list is empty!" << endl;
            return;
        }
        if (evenHead->next == nullptr) {
            delete evenHead;
            evenHead = nullptr;
            evenTail = nullptr;
            return;
        }
        Node* secondLast = evenHead;
        while (secondLast->next->next != nullptr) {
            secondLast = secondLast->next;
        }
        Node* temp = secondLast->next;
        secondLast->next = nullptr;
        evenTail = secondLast;
        delete temp;
    }

    // Get the length of the odd list
    int getLengthOdd() {
        Node* temp = oddHead;
        int length = 0;
        while (temp != nullptr) {
            length++;
            temp = temp->next;
        }
        return length;
    }

    // Get the length of the even list
    int getLengthEven() {
        Node* temp = evenHead;
        int length = 0;
        while (temp != nullptr) {
            length++;
            temp = temp->next;
        }
        return length;
    }

    
};

// Main function to test the linked list
int main() {
    OddEvenList list;

    // Add elements to the list
    list.add(1);   // Odd
    list.add(2);   // Even
    list.add(3);   // Odd
    list.add(4);   // Even

    cout << "List of elements: " << endl;
    list.display();

    cout << "Detailed list info:" << endl;
    list.displayMore();

    // Remove elements from the list
    list.deleteAtStartOdd();
    list.deleteAtEndEven();
    list.deleteAtStartEven();

    cout << "List of elements after removals: " << endl;
    list.display();

    

    return 0;
}