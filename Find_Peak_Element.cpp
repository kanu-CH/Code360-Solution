int findPeakElement(vector<int> &arr) {
    int n = arr.size();
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if mid is a peak element
        bool leftOK = (mid == 0 || arr[mid] > arr[mid - 1]);
        bool rightOK = (mid == n - 1 || arr[mid] > arr[mid + 1]);

        if (leftOK && rightOK) {
            return mid;
        }

        // Move to the side that has a higher element
        if (mid > 0 && arr[mid - 1] > arr[mid]) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    // Should never reach here as there is always a peak element
    return -1;
}
