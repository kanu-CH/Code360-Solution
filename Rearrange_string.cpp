#include <bits/stdc++.h> 
string reArrangeString(string &s)
{
	if (s.empty()) return "not possible";
    
    // Step 1: Count frequencies of each character
    unordered_map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }
    
    // Step 2: Create a max-heap (priority queue) based on character frequencies
    priority_queue<pair<int, char>> maxHeap;
    for (auto entry : freq) {
        maxHeap.push({entry.second, entry.first});
    }
    
    string result;
    pair<int, char> prev = {-1, '#'}; // Previous character and its remaining count
    
    // Step 3: Build the result string
    while (!maxHeap.empty()) {
        auto current = maxHeap.top();
        maxHeap.pop();
        
        // Append current character to the result
        result += current.second;
        
        // If the previous character still has remaining frequency, push it back into the heap
        if (prev.first > 0) {
            maxHeap.push(prev);
        }
        
        // Update the previous character (reduce its frequency)
        current.first--;
        prev = current;
    }
    
    // Step 4: Check if the result string is valid
    if (result.size() == s.size()) {
        return result;
    } else {
        return "not possible";
    }
}
