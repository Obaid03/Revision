// ======================== BINARY SEARCH ALGORITHM ========================
/*
Algorithm: Binary Search (Iterative)
1. Set left = 0, right = n-1
2. While left <= right:
   a. Calculate mid = (left + right) / 2
   b. If arr[mid] == target, return mid
   c. If arr[mid] < target, search right half (left = mid + 1)
   d. If arr[mid] > target, search left half (right = mid - 1)
3. Return -1 if not found
Time Complexity: O(log n)
Space Complexity: O(1)
Note: Array must be sorted
*/
#include <iostream>
using namespace std;

// Binary Search Algorithm - O(log n)
int binarySearch(int arr[], int n, int target) {
    cout << "=== BINARY SEARCH ALGORITHM ===" << endl;
    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Searching for: " << target << endl;
    cout << "Note: Array must be sorted for binary search!" << endl << endl;
    
    int left = 0;
    int right = n - 1;
    int step = 1;
    
    // Binary Search Implementation
    while (left <= right) {
        int mid = left + (right - left) / 2; // Avoid overflow
        
        cout << "Step " << step << ":" << endl;
        cout << "  Left = " << left << ", Right = " << right << ", Mid = " << mid << endl;
        cout << "  arr[" << mid << "] = " << arr[mid] << endl;
        
        if (arr[mid] == target) {
            cout << "  " << target << " == " << arr[mid] << " -> FOUND!" << endl;
            cout << "Element " << target << " found at index " << mid << endl;
            return mid;
        }
        
        if (arr[mid] < target) {
            cout << "  " << arr[mid] << " < " << target << " -> Search RIGHT half" << endl;
            left = mid + 1;
        } else {
            cout << "  " << arr[mid] << " > " << target << " -> Search LEFT half" << endl;
            right = mid - 1;
        }
        
        cout << "  New search range: [" << left << ", " << right << "]" << endl << endl;
        step++;
    }
    
    cout << "Element " << target << " not found in the array!" << endl;
    return -1;
}

// Binary Search (Recursive Implementation)
int binarySearchRecursive(int arr[], int left, int right, int target, int depth = 1) {
    if (depth == 1) {
        cout << "=== BINARY SEARCH (RECURSIVE) ===" << endl;
        cout << "Searching for: " << target << endl << endl;
    }
    
    // Base case
    if (left > right) {
        cout << "Depth " << depth << ": left > right, element not found" << endl;
        return -1;
    }
    
    int mid = left + (right - left) / 2;
    
    cout << "Depth " << depth << ": left=" << left << ", right=" << right 
         << ", mid=" << mid << ", arr[" << mid << "]=" << arr[mid] << endl;
    
    if (arr[mid] == target) {
        cout << "Element found at index " << mid << endl;
        return mid;
    }
    
    if (arr[mid] < target) {
        cout << "  " << arr[mid] << " < " << target << " -> Searching right half" << endl;
        return binarySearchRecursive(arr, mid + 1, right, target, depth + 1);
    } else {
        cout << "  " << arr[mid] << " > " << target << " -> Searching left half" << endl;
        return binarySearchRecursive(arr, left, mid - 1, target, depth + 1);
    }
}

int main() {
    cout << "BINARY SEARCH IMPLEMENTATION" << endl;
    cout << "============================" << endl << endl;
    
    // Test array - MUST BE SORTED for binary search
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 67, 78};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // Test 1: Iterative Binary Search
    int target1 = 23;
    int result1 = binarySearch(arr, n, target1);
    
    cout << endl << "================================" << endl;
    
    // Test 2: Recursive Binary Search
    int target2 = 45;
    int result2 = binarySearchRecursive(arr, 0, n - 1, target2);
    
    cout << endl << "================================" << endl;
    
    // Test 3: Search for non-existing element
    int target3 = 99;
    binarySearch(arr, n, target3);
    
    cout << endl << "Time Complexity: O(log n)" << endl;
    cout << "Space Complexity: O(1) for iterative, O(log n) for recursive" << endl;
    cout << "Prerequisite: Array must be sorted" << endl;
    cout << "Best Case: O(1) - element found at middle" << endl;
    cout << "Worst Case: O(log n)" << endl;
    
    return 0;
}
