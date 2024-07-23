#include <bits/stdc++.h> 
vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    vector<int> result;
    unordered_map<int, int> freq;
    int distinctCount = 0;

    // Initialize the frequency map for the first window
    for (int i = 0; i < k; ++i) {
        if (freq[arr[i]] == 0) {
            ++distinctCount;
        }
        ++freq[arr[i]];
    }
    result.push_back(distinctCount);

    // Slide the window across the array
    for (int i = k; i < arr.size(); ++i) {
        int newElement = arr[i];
        int oldElement = arr[i - k];

        // Remove the old element from the frequency map
        if (freq[oldElement] == 1) {
            --distinctCount;
        }
        --freq[oldElement];

        // Add the new element to the frequency map
        if (freq[newElement] == 0) {
            ++distinctCount;
        }
        ++freq[newElement];

        result.push_back(distinctCount);
    }

    return result;
	
}
