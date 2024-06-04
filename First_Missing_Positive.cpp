#include <bits/stdc++.h> 
int firstMissing(int arr[], int n)
{
    // Rearrange elements to their correct positions
    for (int i = 0; i < n; i++) {
        // While the current element is in the range [1, n] and is not in its correct position
        while (arr[i] > 0 && arr[i] <= n && arr[arr[i] - 1] != arr[i]) {
            swap(arr[i], arr[arr[i] - 1]);
        }
    }
    
    // Find the first position where the element is not i + 1
    for (int i = 0; i < n; i++) {
        if (arr[i] != i + 1) {
            return i + 1;
        }
    }
    
    // If all positions are correct, the missing number is n + 1
    return n + 1;
}
