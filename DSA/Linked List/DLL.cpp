#include <iostream>
using namespace std;

// ======================== DOUBLY LINKED LIST ========================

// Node Class for Doubly Linked List
class DNode {
public:
    int data;
    DNode* next;
    DNode* prev;
    
    // Constructor
    DNode(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

// Doubly Linked List Class
class DoublyLinkedList {
private:
    DNode* head;
    DNode* tail;
    
public:
    // Constructor
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }
    
    // 1. INSERT AT BEGINNING - O(1)
    void insertAtBeginning(int value) {
        DNode* newNode = new DNode(value);
        
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        cout << "Inserted " << value << " at beginning" << endl;
    }
    
    // 2. INSERT AT END - O(1)
    void insertAtEnd(int value) {
        DNode* newNode = new DNode(value);
        
        if (tail == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        cout << "Inserted " << value << " at end" << endl;
    }
    
    // 3. INSERT AT POSITION - O(n)
    void insertAtPosition(int value, int position) {
        if (position == 0) {
            insertAtBeginning(value);
            return;
        }
        
        DNode* newNode = new DNode(value);
        DNode* temp = head;
        
        for (int i = 0; i < position && temp != nullptr; i++) {
            temp = temp->next;
        }
        
        if (temp == nullptr) {
            insertAtEnd(value);
            return;
        }
        
        newNode->next = temp;
        newNode->prev = temp->prev;
        temp->prev->next = newNode;
        temp->prev = newNode;
        cout << "Inserted " << value << " at position " << position << endl;
    }
    
    // 4. DELETE FROM BEGINNING - O(1)
    void deleteFromBeginning() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        
        DNode* temp = head;
        cout << "Deleted " << temp->data << " from beginning" << endl;
        
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
    }
    
    // 5. DELETE FROM END - O(1)
    void deleteFromEnd() {
        if (tail == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        
        DNode* temp = tail;
        cout << "Deleted " << temp->data << " from end" << endl;
        
        if (head == tail) {
            head = tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
    }
    
    // 6. DELETE BY VALUE - O(n)
    void deleteByValue(int value) {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        
        DNode* temp = head;
        while (temp != nullptr && temp->data != value) {
            temp = temp->next;
        }
        
        if (temp == nullptr) {
            cout << "Value " << value << " not found" << endl;
            return;
        }
        
        if (temp == head) {
            deleteFromBeginning();
        } else if (temp == tail) {
            deleteFromEnd();
        } else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            cout << "Deleted " << value << " from list" << endl;
            delete temp;
        }
    }
    
    // 7. DISPLAY FORWARD - O(n)
    void displayForward() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        
        cout << "Doubly Linked List (Forward): NULL <-> ";
        DNode* temp = head;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr) cout << " <-> ";
            temp = temp->next;
        }
        cout << " <-> NULL" << endl;
    }
    
    // 8. DISPLAY BACKWARD - O(n)
    void displayBackward() {
        if (tail == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        
        cout << "Doubly Linked List (Backward): NULL <-> ";
        DNode* temp = tail;
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->prev != nullptr) cout << " <-> ";
            temp = temp->prev;
        }
        cout << " <-> NULL" << endl;
    }
    
    // 9. SEARCH - O(n)
    bool search(int value) {
        DNode* temp = head;
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
    
    // Destructor
    ~DoublyLinkedList() {
        while (head != nullptr) {
            DNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
};
