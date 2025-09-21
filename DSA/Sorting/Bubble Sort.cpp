// ======================== BUBBLE SORT ALGORITHM ========================
/*
Algorithm: Bubble Sort
1. Compare adjacent elements
2. Swap if they're in wrong order
3. Repeat for all elements
4. After each pass, largest element reaches its correct position
Time Complexity: O(n²)
Space Complexity: O(1)
*/
#include <iostream>
using namespace std;

// Bubble Sort Algorithm - O(n²)
void bubbleSort(int arr[], int n) {
    cout << "=== BUBBLE SORT ALGORITHM ===" << endl;
    cout << "Original Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl << endl;
    
    // Bubble Sort Implementation
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false; // Optimization flag
        cout << "Pass " << (i + 1) << ":" << endl;
        
        for (int j = 0; j < n - i - 1; j++) {
            cout << "  Comparing " << arr[j] << " and " << arr[j + 1];
            
            // Compare adjacent elements
            if (arr[j] > arr[j + 1]) {
                // Swap if they are in wrong order
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
                cout << " -> Swapped!";
            } else {
                cout << " -> No swap needed";
            }
            cout << endl;
        }
        
        // Print array after each pass
        cout << "  Array after pass " << (i + 1) << ": ";
        for (int k = 0; k < n; k++) {
            cout << arr[k] << " ";
        }
        cout << endl << endl;
        
        // Early termination if array is sorted
        if (!swapped) {
            cout << "Array is already sorted! Stopping early." << endl;
            break;
        }
    }
    
    cout << "Final Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    cout << "BUBBLE SORT IMPLEMENTATION" << endl;
    cout << "=========================" << endl << endl;
    
    // Test array
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // Call bubble sort
    bubbleSort(arr, n);
    
    cout << endl << "Time Complexity: O(n²)" << endl;
    cout << "Space Complexity: O(1)" << endl;
    cout << "Best Case: O(n) when array is already sorted" << endl;
    
    return 0;
}
