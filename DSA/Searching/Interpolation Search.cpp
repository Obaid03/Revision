// ======================== INTERPOLATION SEARCH ALGORITHM ========================
/*
Algorithm: Interpolation Search
1. Estimate position using interpolation formula
2. pos = low + [(target - arr[low]) / (arr[high] - arr[low])] * (high - low)
3. Compare with target and adjust bounds
Time Complexity: O(log log n) for uniformly distributed data, O(n) worst case
Space Complexity: O(1)
Note: Works best with uniformly distributed sorted data
*/
int interpolationSearch(int arr[], int n, int target) {
    cout << "\n=== INTERPOLATION SEARCH ALGORITHM ===" << endl;
    cout << "Searching for " << target << " in sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    int low = 0;
    int high = n - 1;
    int step = 1;
    
    while (low <= high && target >= arr[low] && target <= arr[high]) {
        if (low == high) {
            if (arr[low] == target) {
                cout << "FOUND! Element " << target << " is at index " << low << endl;
                return low;
            }
            break;
        }
        
        // Interpolation formula
        int pos = low + ((double)(target - arr[low]) / (arr[high] - arr[low])) * (high - low);
        
        cout << "Step " << step << ": low=" << low << ", high=" << high 
             << ", estimated pos=" << pos << ", arr[pos]=" << arr[pos] << endl;
        
        if (arr[pos] == target) {
            cout << "FOUND! Element " << target << " is at index " << pos << endl;
            return pos;
        }
        
        if (arr[pos] < target) {
            cout << "arr[pos] < target, searching right portion" << endl;
            low = pos + 1;
        } else {
            cout << "arr[pos] > target, searching left portion" << endl;
            high = pos - 1;
        }
        step++;
    }
    
    cout << "Element " << target << " not found in array" << endl;
    return -1;
}
