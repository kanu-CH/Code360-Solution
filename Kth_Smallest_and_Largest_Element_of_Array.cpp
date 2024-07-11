#include <algorithm> 
vector<int> kthSmallLarge(vector<int> &arr, int n, int k)
{
	// Step 1: Sort the array
    sort(arr.begin(), arr.end());

    // Step 2: Find the Kth smallest and Kth largest elements
    int kthSmallest = arr[k - 1];
    int kthLargest = arr[n - k];

    // Step 3: Return the results as a vector
    return {kthSmallest, kthLargest};
}
