// ======================== BINARY SEARCH ALGORITHM ========================
// Algorithm: Binary Search (Iterative)
// 1. Set left = 0, right = n-1
// 2. While left <= right:
//    a. mid = (left + right) / 2
//    b. If arr[mid] == target → return mid
//    c. If arr[mid] < target → left = mid + 1
//    d. If arr[mid] > target → right = mid - 1
// 3. Return -1 if not found
// Time Complexity: O(log n)
// Space Complexity: O(1)
// Note: Array must be sorted

#include <iostream>
using namespace std;

// Iterative Binary Search
int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

// Recursive Binary Search
int binarySearchRecursive(int arr[], int left, int right, int target) {
    if (left > right)
        return -1;

    int mid = left + (right - left) / 2;

    if (arr[mid] == target)
        return mid;
    else if (arr[mid] < target)
        return binarySearchRecursive(arr, mid + 1, right, target);
    else
        return binarySearchRecursive(arr, left, mid - 1, target);
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 67, 78};
    int n = sizeof(arr) / sizeof(arr[0]);

    int target1 = 23;
    int result1 = binarySearch(arr, n, target1);
    if (result1 != -1)
        cout << "Element " << target1 << " found at index " << result1 << " (Iterative)" << endl;
    else
        cout << "Element " << target1 << " not found (Iterative)" << endl;

    int target2 = 45;
    int result2 = binarySearchRecursive(arr, 0, n - 1, target2);
    if (result2 != -1)
        cout << "Element " << target2 << " found at index " << result2 << " (Recursive)" << endl;
    else
        cout << "Element " << target2 << " not found (Recursive)" << endl;

    int target3 = 99;
    int result3 = binarySearch(arr, n, target3);
    if (result3 != -1)
        cout << "Element " << target3 << " found at index " << result3 << endl;
    else
        cout << "Element " << target3 << " not found in the array" << endl;

    return 0;
}
