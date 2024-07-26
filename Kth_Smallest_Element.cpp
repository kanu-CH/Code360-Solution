int kthSmallest(int n,int k,vector<int> Arr)
{
   // Sort the array
    sort(Arr.begin(), Arr.end());
    // Return the K-th smallest element (1-based index, hence K-1 in 0-based indexing)
    return Arr[k - 1];
}
