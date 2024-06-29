int removeDuplicates(vector<int> &arr, int n) {
	if (n == 0) return 0;

    int j = 0;  // index for the unique elements

    // Iterate through the array
    for (int i = 1; i < n; ++i) {
        if (arr[i] != arr[j]) {  // found a new unique element
            ++j;                // move to the next position
            arr[j] = arr[i];    // update the position with the unique element
        }
    }

    // Return the length of the array with unique elements
    return j + 1;
}
