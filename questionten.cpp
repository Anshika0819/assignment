#include <iostream>
#include <string>

using namespace std;

// Structure to represent a contact
struct Contact {
    string name;
    string mobileNumber;
    Contact* next;
};

// Function to create a new contact node
Contact* createContact(string name, string mobileNumber) {
    Contact* newContact = new Contact();
    newContact->name = name;
    newContact->mobileNumber = mobileNumber;
    newContact->next = nullptr;
    return newContact;
}
// Function to insert a new contact at the beginning of the list
void insertContact(Contact** head, string name, string mobileNumber) {
    Contact* newContact = createContact(name, mobileNumber);
    newContact->next = *head;
    *head = newContact;
}

// Function to print all contacts in the list
void printContacts(Contact* head) {
    while (head != nullptr) {
        cout << "Name: " << head->name << ", Mobile Number: " << head->mobileNumber << endl;
        head = head->next;
    }
}

// Function to search for a contact by name
Contact* searchContact(Contact* head, string name) {
    while (head != nullptr) {
        if (head->name == name) {
  return head;
        }
        head = head->next;
    }
    return nullptr;
}
// Function to delete a contact by name
void deleteContact(Contact** head, string name) {
    Contact* current = *head;
    Contact* previous = nullptr;

    while (current != nullptr) {
        if (current->name == name) {
            if (previous == nullptr) {
                *head = current->next;
            } else {
                previous->next = current->next;
            }
            delete current;
            return;
        }
        previous = current;
        current = current->next;
    }
}

int main() {
    Contact* head = nullptr;

    insertContact(&head, "John", "1234567890");
    insertContact(&head, "Alice", "9876543210");
    insertContact(&head, "Bob", "5551234567");

    printContacts(head);

    Contact* foundContact = searchContact(head, "Alice");
    if (foundContact != nullptr) {
 cout << "Found contact: " << foundContact->name << ", Mobile Number: " << foundContact->mobileNumber << endl;
    } else {
        cout << "Contact not found" << endl;
    }

    deleteContact(&head, "Bob");
    printContacts(head);

return 0;
}