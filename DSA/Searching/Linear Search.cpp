// ======================== LINEAR SEARCH ALGORITHM ========================
/*
Algorithm: Linear Search
1. Start from first element
2. Compare each element with target
3. Return index if found, -1 if not found
Time Complexity: O(n)
Space Complexity: O(1)
*/
#include <iostream>
using namespace std;

// Linear Search Algorithm - O(n)
int linearSearch(int arr[], int n, int target) {
    cout << "=== LINEAR SEARCH ALGORITHM ===" << endl;
    cout << "Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Searching for: " << target << endl << endl;
    
    // Linear Search Implementation
    for (int i = 0; i < n; i++) {
        cout << "Step " << (i + 1) << ": Checking arr[" << i << "] = " << arr[i];
        
        if (arr[i] == target) {
            cout << " -> FOUND!" << endl;
            cout << "Element " << target << " found at index " << i << endl;
            return i; // Return index if found
        }
        cout << " -> Not a match, continue searching..." << endl;
    }
    
    cout << "Element " << target << " not found in the array!" << endl;
    return -1; // Return -1 if not found
}

// Function to find all occurrences
void linearSearchAll(int arr[], int n, int target) {
    cout << endl << "=== FINDING ALL OCCURRENCES ===" << endl;
    cout << "Searching for all occurrences of " << target << endl;
    
    bool found = false;
    cout << "Positions where " << target << " is found: ";
    
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            cout << i << " ";
            found = true;
        }
    }
    
    if (!found) {
        cout << "None";
    }
    cout << endl;
}

int main() {
    cout << "LINEAR SEARCH IMPLEMENTATION" << endl;
    cout << "============================" << endl << endl;
    
    // Test array
    int arr[] = {10, 25, 30, 15, 25, 40, 55, 25};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // Test 1: Search for existing element
    int target1 = 30;
    int result1 = linearSearch(arr, n, target1);
    
    cout << endl << "------------------------" << endl;
    
    // Test 2: Search for non-existing element
    int target2 = 99;
    int result2 = linearSearch(arr, n, target2);
    
    // Test 3: Find all occurrences
    linearSearchAll(arr, n, 25);
    
    cout << endl << "Time Complexity: O(n)" << endl;
    cout << "Space Complexity: O(1)" << endl;
    cout << "Best Case: O(1) - element found at first position" << endl;
    cout << "Worst Case: O(n) - element at last position or not found" << endl;
    
    return 0;
}
