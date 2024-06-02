vector<int> rotateArray(vector<int>arr, int k) {
    int n = arr.size();
    if (n == 0) return arr; // Edge case: empty array
    k = k % n; // Normalize k
    vector<int> rotatedArray;
    
    // Add elements from k to end of the array
    for (int i = k; i < n; i++) {
        rotatedArray.push_back(arr[i]);
    }
    
    // Add elements from start to k-1
    for (int i = 0; i < k; i++) {
        rotatedArray.push_back(arr[i]);
    }
    
    return rotatedArray;
}
