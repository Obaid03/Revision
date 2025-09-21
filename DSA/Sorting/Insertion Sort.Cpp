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

// Insertion Sort Algorithm - O(n²)
void insertionSort(int arr[], int n) {
    cout << "=== INSERTION SORT ALGORITHM ===" << endl;
    cout << "Original Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl << endl;
    
    // Insertion Sort Implementation
    for (int i = 1; i < n; i++) {
        int key = arr[i]; // Current element to be inserted
        int j = i - 1;
        
        cout << "Pass " << i << ":" << endl;
        cout << "  Key = " << key << " (element at position " << i << ")" << endl;
        cout << "  Inserting into sorted portion: ";
        for (int k = 0; k < i; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;
        
        // Move elements greater than key one position ahead
        while (j >= 0 && arr[j] > key) {
            cout << "    Moving " << arr[j] << " from position " << j 
                 << " to position " << (j + 1) << endl;
            arr[j + 1] = arr[j];
            j--;
        }
        
        // Insert the key at correct position
        arr[j + 1] = key;
        cout << "  Inserted " << key << " at position " << (j + 1) << endl;
        
        // Print array after each pass
        cout << "  Array after pass " << i << ": ";
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
    cout << "INSERTION SORT IMPLEMENTATION" << endl;
    cout << "=============================" << endl << endl;
    
    // Test array
    int arr[] = {5, 2, 4, 6, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // Call insertion sort
    insertionSort(arr, n);
    
    cout << endl << "Time Complexity:" << endl;
    cout << "  Best Case: O(n) - when array is already sorted" << endl;
    cout << "  Average Case: O(n²)" << endl;
    cout << "  Worst Case: O(n²) - when array is reverse sorted" << endl;
    cout << "Space Complexity: O(1)" << endl;
    
    return 0;
}
