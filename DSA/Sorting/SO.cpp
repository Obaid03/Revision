//Bubble Sort
void BubbleSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int flag=0;
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                flag=1;
            }
        }
        if(!flag){
            cout<<"Array Sorted!, Stopping early"<<endl;
        }
    }
    printArray(arr,n);
  }
//Selection Sort
void SelectionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
       int min_index=i;
       for(int j=i+1;j<n;j++){
        if(arr[j]<arr[min_index]){
            min_index=j;
        }
       }
       if(min_index!=i){
        int temp=arr[i];
        arr[i]=arr[min_index];
        arr[min_index]=temp;
    }
    }
    printArray(arr,n);
  }
//Insertion Sort
void InsertionSort(int arr[],int n){
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0&&arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
    printArray(arr,n);
  }
// Shelll Sort
void ShellSort(int arr[],int n){
    for(int gap=n/2;gap>=1;gap/=2){
        for(int i=gap;i<n;i++){
            int key=arr[i];
            int j=i-gap;
            while(j>=0&&arr[j]>key){
                arr[j+gap]=arr[j];
                j-=gap;
            }
            arr[j+gap]=key;
        }
    }
    printArray(arr,n);
  }
//Comb Sort
void combSort(int arr[], int n) {
    float shrink = 1.3;   // Shrink factor
    int gap = n;          // Initialize gap to size of array
    bool swapped = true;  // Flag to check if swapping occurred
    // Continue until gap becomes 1 and array is sorted
    while (gap > 1 || swapped) {
        // Update the gap using the shrink factor
        gap = int(gap / shrink);
        if (gap < 1) {
            gap = 1;  // Ensure gap is at least 1
        }
        swapped = false;
        // Perform a gapped bubble sort
        for (int i = 0; i + gap < n; ++i) {
            if (arr[i] > arr[i + gap]) {
                // Swap arr[i] and arr[i + gap]
                int temp = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = temp;
                swapped = true;
            }
        }
    }
}
