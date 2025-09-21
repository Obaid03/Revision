#include <iostream>
using namespace std;

// ======================== SINGLY LINKED LIST ========================

// Node Class for Singly Linked List
class Node {
public:
    int data;
    Node* next;
    
    // Constructor
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Singly Linked List Class
class SinglyLinkedList {
private:
    Node* head;
    
public:
    // Constructor
    SinglyLinkedList() {
        head = nullptr;
    }
    
    // 1. INSERT AT BEGINNING - O(1)
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        cout << "Inserted " << value << " at beginning" << endl;
    }
    
    // 2. INSERT AT END - O(n)
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        
        if (head == nullptr) {
            head = newNode;
            return;
        }
        
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        cout << "Inserted " << value << " at end" << endl;
    }
    
    // 3. INSERT AT POSITION - O(n)
    void insertAtPosition(int value, int position) {
        if (position == 0) {
            insertAtBeginning(value);
            return;
        }
        
        Node* newNode = new Node(value);
        Node* temp = head;
        
        for (int i = 0; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
        
        if (temp == nullptr) {
            cout << "Position out of bounds" << endl;
            return;
        }
        
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Inserted " << value << " at position " << position << endl;
    }
    
    // 4. DELETE FROM BEGINNING - O(1)
    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        
        Node* temp = head;
        head = head->next;
        cout << "Deleted " << temp->data << " from beginning" << endl;
        delete temp;
    }
    
    // 5. DELETE FROM END - O(n)
    void deleteFromEnd() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        
        if (head->next == nullptr) {
            cout << "Deleted " << head->data << " from end" << endl;
            delete head;
            head = nullptr;
            return;
        }
        
        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        
        cout << "Deleted " << temp->next->data << " from end" << endl;
        delete temp->next;
        temp->next = nullptr;
    }
    
    // 6. DELETE BY VALUE - O(n)
    void deleteByValue(int value) {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        
        if (head->data == value) {
            deleteFromBeginning();
            return;
        }
        
        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != value) {
            temp = temp->next;
        }
        
        if (temp->next == nullptr) {
            cout << "Value " << value << " not found" << endl;
            return;
        }
        
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        cout << "Deleted " << value << " from list" << endl;
        delete nodeToDelete;
    }
    
    // 7. SEARCH - O(n)
    bool search(int value) {
        Node* temp = head;
        int position = 0;
        
        while (temp != nullptr) {
            if (temp->data == value) {
                cout << "Found " << value << " at position " << position << endl;
                return true;
            }
            temp = temp->next;
            position++;
        }
        
        cout << "Value " << value << " not found" << endl;
        return false;
    }
    
    // 8. DISPLAY - O(n)
    void display() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        
        cout << "Singly Linked List: ";
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) cout << " -> ";
            temp = temp->next;
        }
        cout << " -> NULL" << endl;
    }
    
    // 9. GET LENGTH - O(n)
    int getLength() {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }
    
    // 10. REVERSE LIST - O(n)
    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        
        head = prev;
        cout << "List reversed successfully" << endl;
    }
    
    // Destructor
    ~SinglyLinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};
