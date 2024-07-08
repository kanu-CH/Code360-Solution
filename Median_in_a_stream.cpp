#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <cmath>
vector<int> findMedian(vector<int> &arr, int n){
	// Max-heap for the lower half
    priority_queue<int> maxHeap;
    // Min-heap for the upper half
    priority_queue<int, vector<int>, greater<int>> minHeap;

    vector<int> medians;

    for (int i = 0; i < n; ++i) {
        int num = arr[i];

        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }

        // Balance the heaps
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

        // Find the median
        if (maxHeap.size() > minHeap.size()) {
            medians.push_back(maxHeap.top());
        } else {
            int median = floor((maxHeap.top() + minHeap.top()) / 2.0);
            medians.push_back(median);
        }
    }
    return medians;
}
