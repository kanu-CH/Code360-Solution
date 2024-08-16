#include <bits/stdc++.h> 
int minimumValueFunction(string s, int n, int k) {
	// Step 1: Count frequency of each character
    unordered_map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }
    
    // Step 2: Use a max heap to store frequencies
    priority_queue<int> maxHeap;
    for (auto entry : freq) {
        maxHeap.push(entry.second);
    }
    
    // Step 3: Remove characters k times
    while (k > 0 && !maxHeap.empty()) {
        int top = maxHeap.top();
        maxHeap.pop();
        top--;  // Reduce the highest frequency
        k--;
        if (top > 0) {
            maxHeap.push(top);  // Push it back if still > 0
        }
    }
    
    // Step 4: Calculate the sum of squares of the remaining frequencies
    int result = 0;
    while (!maxHeap.empty()) {
        int freq = maxHeap.top();
        maxHeap.pop();
        result += freq * freq;
    }
    
    return result;
}
