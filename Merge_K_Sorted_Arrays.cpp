#include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>& kArrays, int k) {
    // Priority queue to store the elements along with their array index and element index
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> minHeap;
    
    // Initial population of the heap with the first element of each array
    for (int i = 0; i < k; ++i) {
        if (!kArrays[i].empty()) {
            minHeap.push(make_tuple(kArrays[i][0], i, 0));
        }
    }
    
    vector<int> result;
    
    while (!minHeap.empty()) {
        tuple<int, int, int> top = minHeap.top();
        minHeap.pop();
        
        int value = get<0>(top);
        int arrayIdx = get<1>(top);
        int elementIdx = get<2>(top);
        
        result.push_back(value);
        
        // If there is a next element in the same array, push it into the heap
        if (elementIdx + 1 < kArrays[arrayIdx].size()) {
            minHeap.push(make_tuple(kArrays[arrayIdx][elementIdx + 1], arrayIdx, elementIdx + 1));
        }
    }
    
    return result;
}
