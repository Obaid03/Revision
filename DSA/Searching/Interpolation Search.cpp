// ======================== INTERPOLATION SEARCH ALGORITHM ========================
// Algorithm: Interpolation Search (Iterative)
// 1. Set low = 0, high = n - 1
// 2. While low <= high and target >= arr[low] and target <= arr[high]:
//    a. pos = low + [(target - arr[low]) * (high - low)] / (arr[high] - arr[low])
//    b. If arr[pos] == target → return pos
//    c. If arr[pos] < target → low = pos + 1
//    d. If arr[pos] > target → high = pos - 1
// 3. Return -1 if not found
// Time Complexity: O(log log n) for uniformly distributed data
// Worst Case: O(n)
// Space Complexity: O(1)
// Note: Array must be sorted and preferably uniformly distributed

#include <iostream>
using namespace std;

// Iterative Interpolation Search
int interpolationSearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;

    while (low <= high && target >= arr[low] && target <= arr[high]) {
        // Avoid division by zero
        if (arr[low] == arr[high])
            break;

        // Estimate the position
        int pos = low + ((target - arr[low]) * (high - low)) / (arr[high] - arr[low]);

        if (arr[pos] == target)
            return pos;
        else if (arr[pos] < target)
            low = pos + 1;
        else
            high = pos - 1;
    }

    return -1;
}

// Recursive Interpolation Search
int interpolationSearchRecursive(int arr[], int low, int high, int target) {
    if (low <= high && target >= arr[low] && target <= arr[high]) {
        if (arr[low] == arr[high])
            return (arr[low] == target) ? low : -1;

        int pos = low + ((target - arr[low]) * (high - low)) / (arr[high] - arr[low]);

        if (arr[pos] == target)
            return pos;
        else if (arr[pos] < target)
            return interpolationSearchRecursive(arr, pos + 1, high, target);
        else
            return interpolationSearchRecursive(arr, low, pos - 1, target);
    }

    return -1;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int n = sizeof(arr) / sizeof(arr[0]);

    int target1 = 70;
    int result1 = interpolationSearch(arr, n, target1);
    if (result1 != -1)
        cout << "Element " << target1 << " found at index " << result1 << " (Iterative)" << endl;
    else
        cout << "Element " << target1 << " not found (Iterative)" << endl;

    int target2 = 30;
    int result2 = interpolationSearchRecursive(arr, 0, n - 1, target2);
    if (result2 != -1)
        cout << "Element " << target2 << " found at index " << result2 << " (Recursive)" << endl;
    else
        cout << "Element " << target2 << " not found (Recursive)" << endl;

    int target3 = 95;
    int result3 = interpolationSearch(arr, n, target3);
    if (result3 != -1)
        cout << "Element " << target3 << " found at index " << result3 << endl;
    else
        cout << "Element " << target3 <<
