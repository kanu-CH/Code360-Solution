int searchInsert(vector<int>& arr, int m)
{
	int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == m) {
            return mid;
        } else if (arr[mid] > m) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return left; 
}
