int binarySearch(vector<int> &arr, int s, int e, int k){
    if(s>e)
        return -1;
    int mid= s + (e-s)/2;
    if(arr[mid]==k)
        return mid;
    else if(arr[mid]<k)
        return binarySearch(arr, mid+1, e, k); 
    return binarySearch(arr, s, mid-1, k);
}
int search(vector<int> &nums, int target) {
    int s=0;
    int e=nums.size()-1;
    int res =binarySearch(nums, s, e, target);
    return res;
}
