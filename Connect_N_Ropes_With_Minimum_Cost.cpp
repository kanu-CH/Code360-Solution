long long connectRopes(int* arr, int n) {
    // Min-heap to store the rope lengths
    priority_queue<int, vector<int>, greater<int>> minHeap;

    // Insert all ropes into the min-heap
    for (int i = 0; i < n; ++i) {
        minHeap.push(arr[i]);
    }

    long long totalCost = 0;

    // Continue until only one rope is left in the heap
    while (minHeap.size() > 1) {
        // Extract the two shortest ropes
        int first = minHeap.top();
        minHeap.pop();
        int second = minHeap.top();
        minHeap.pop();

        // Connect the two ropes
        int newRope = first + second;
        totalCost += newRope;

        // Insert the new rope back into the heap
        minHeap.push(newRope);
    }

    return totalCost;
}
