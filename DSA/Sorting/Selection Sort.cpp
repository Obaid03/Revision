// ======================== SELECTION SORT ALGORITHM ========================
/*
Algorithm: Selection Sort
1. Find minimum element in unsorted portion
2. Swap it with first element of unsorted portion
3. Move boundary of unsorted portion
4. Repeat until array is sorted
Time Complexity: O(n²)
Space Complexity: O(1)
*/
#include <iostream>
using namespace std;

// Selection Sort Algorithm - O(n²)
void selectionSort(int arr[], int n) {
    cout << "=== SELECTION SORT ALGORITHM ===" << endl;
    cout << "Original Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl << endl;
    
    // Selection Sort Implementation
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i; // Assume first element is minimum
        cout << "Pass " << (i + 1) << ":" << endl;
        cout << "  Finding minimum from position " << i << " to " << (n-1) << endl;
        
        // Find minimum element in remaining unsorted array
        for (int j = i + 1; j < n; j++) {
            cout << "    Comparing arr[" << minIndex << "]=" << arr[minIndex] 
                 << " with arr[" << j << "]=" << arr[j];
            
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
                cout << " -> New minimum found at index " << j;
            }
            cout << endl;
        }
        
        // Swap the found minimum element with first element
        if (minIndex != i) {
            cout << "  Swapping arr[" << i << "]=" << arr[i] 
                 << " with arr[" << minIndex << "]=" << arr[minIndex] << endl;
            
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        } else {
            cout << "  No swap needed, minimum is already at correct position" << endl;
        }
        
        // Print array after each pass
        cout << "  Array after pass " << (i + 1) << ": ";
        for (int k = 0; k < n; k++) {
            if (k <= i) cout << "[" << arr[k] << "] "; // Sorted portion
            else cout << arr[k] << " "; // Unsorted portion
        }
        cout << endl << endl;
    }
    
    cout << "Final Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    cout << "SELECTION SORT IMPLEMENTATION" << endl;
    cout << "=============================" << endl << endl;
    
    // Test array
    int arr[] = {29, 10, 14, 37, 13, 25, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // Call selection sort
    selectionSort(arr, n);
    
    cout << endl << "Time Complexity: O(n²) in all cases" << endl;
    cout << "Space Complexity: O(1)" << endl;
    cout << "Number of swaps: At most n-1" << endl;
    
    return 0;
}
