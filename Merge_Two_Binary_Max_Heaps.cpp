#include <bits/stdc++.h> 
void heapify(vector<int>& arr, int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // left child index
    int right = 2 * i + 2; // right child index

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}
vector<int> mergeHeap(int n, int m, vector<int> &arr1, vector<int> &arr2) {
    // Step 1: Merge both array
    vector<int> ans;
    for(auto i: arr1)
        ans.push_back(i);
    for(auto i: arr2)
        ans.push_back(i);
    
    //Step 2: Build heap using merged array
    int len = ans.size();
    for(int i = len/2 - 1; i>=0; i--)
        heapify(ans, len, i);
    return ans;
}
