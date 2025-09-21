#include <iostream>
using namespace std;

// ======================== CIRCULAR LINKED LIST ========================

// Node Class for Circular Linked List
class CNode {
public:
    int data;
    CNode* next;
    
    // Constructor
    CNode(int value) {
        data = value;
        next = nullptr;
    }
};

// Circular Linked List Class
class CircularLinkedList {
private:
    CNode* tail; // We use tail instead of head for easier insertion at end
    
public:
    // Constructor
    CircularLinkedList() {
        tail = nullptr;
    }
    
    // 1. INSERT AT BEGINNING - O(1)
    void insertAtBeginning(int value) {
        CNode* newNode = new CNode(value);
        
        if (tail == nullptr) {
            tail = newNode;
            newNode->next = newNode; // Point to itself
        } else {
            newNode->next = tail->next;
            tail->next = newNode;
        }
        cout << "Inserted " << value << " at beginning" << endl;
    }
    
    // 2. INSERT AT END - O(1)
    void insertAtEnd(int value) {
        CNode* newNode = new CNode(value);
        
        if (tail == nullptr) {
            tail = newNode;
            newNode->next = newNode; // Point to itself
        } else {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode; // Update tail
        }
        cout << "Inserted " << value << " at end" << endl;
    }
    
    // 3. INSERT AT POSITION - O(n)
    void insertAtPosition(int value, int position) {
        if (position == 0) {
            insertAtBeginning(value);
            return;
        }
        
        if (tail == nullptr) {
            cout << "List is empty, inserting at beginning" << endl;
            insertAtBeginning(value);
            return;
        }
        
        CNode* newNode = new CNode(value);
        CNode* temp = tail->next; // Start from head
        
        for (int i = 0; i < position - 1; i++) {
            temp = temp->next;
            if (temp == tail->next) { // Completed one full circle
                cout << "Position out of bounds, inserting at end" << endl;
                insertAtEnd(value);
                return;
            }
        }
        
        newNode->next = temp->next;
        temp->next = newNode;
        
        if (temp == tail) { // If inserted after tail, update tail
            tail = newNode;
        }
        
        cout << "Inserted " << value << " at position " << position << endl;
    }
    
    // 4. DELETE FROM BEGINNING - O(1)
    void deleteFromBeginning() {
        if (tail == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        
        CNode* head = tail->next;
        cout << "Deleted " << head->data << " from beginning" << endl;
        
        if (tail == head) { // Only one node
            delete tail;
            tail = nullptr;
        } else {
            tail->next = head->next;
            delete head;
        }
    }
    
    // 5. DELETE FROM END - O(n)
    void deleteFromEnd() {
        if (tail == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        
        cout << "Deleted " << tail->data << " from end" << endl;
        
        if (tail->next == tail) { // Only one node
            delete tail;
            tail = nullptr;
        } else {
            CNode* temp = tail->next;
            while (temp->next != tail) {
                temp = temp->next;
            }
            temp->next = tail->next;
            delete tail;
            tail = temp;
        }
    }
    
    // 6. DELETE BY VALUE - O(n)
    void deleteByValue(int value) {
        if (tail == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        
        CNode* head = tail->next;
        
        // If head contains the value
        if (head->data == value) {
            deleteFromBeginning();
            return;
        }
        
        CNode* temp = head;
        while (temp->next != head && temp->next->data != value) {
            temp = temp->next;
        }
        
        if (temp->next == head) {
            cout << "Value " << value << " not found" << endl;
            return;
        }
        
        CNode* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        
        if (nodeToDelete == tail) {
            tail = temp;
        }
        
        cout << "Deleted " << value << " from list" << endl;
        delete nodeToDelete;
    }
    
    // 7. DISPLAY - O(n)
    void display() {
        if (tail == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        
        cout << "Circular Linked List: ";
        CNode* temp = tail->next; // Start from head
        do {
            cout << temp->data;
            temp = temp->next;
            if (temp != tail->next) cout << " -> ";
        } while (temp != tail->next);
        cout << " -> (back to " << tail->next->data << ")" << endl;
    }
    
    // 8. SEARCH - O(n)
    bool search(int value) {
        if (tail == nullptr) {
            cout << "List is empty" << endl;
            return false;
        }
        
        CNode* temp = tail->next;
        int position = 0;
        
        do {
            if (temp->data == value) {
                cout << "Found " << value << " at position " << position << endl;
                return true;
            }
            temp = temp->next;
            position++;
        } while (temp != tail->next);
        
        cout << "Value " << value << " not found" << endl;
        return false;
    }
    
    // 9. GET LENGTH - O(n)
    int getLength() {
        if (tail == nullptr) return 0;
        
        int count = 0;
        CNode* temp = tail->next;
        do {
            count++;
            temp = temp->next;
        } while (temp != tail->next);
        
        return count;
    }
    
    // Destructor
    ~CircularLinkedList() {
        if (tail == nullptr) return;
        
        CNode* temp = tail->next;
        while (temp != tail) {
            CNode* nodeToDelete = temp;
            temp = temp->next;
            delete nodeToDelete;
        }
        delete tail;
    }
};
