#include <bits/stdc++.h> 
int getLongestSubarray(vector<int>& nums, int k){
    unordered_map<int, int> cumulative_sum_index; // To store the first occurrence of each cumulative sum
    int cumulative_sum = 0; // Initialize cumulative sum
    int max_len = 0; // Initialize max length of subarray
    
    for (int i = 0; i < nums.size(); ++i) {
        cumulative_sum += nums[i]; // Update cumulative sum
        
        if (cumulative_sum == k) {
            // If the cumulative sum itself is equal to k, update max_len
            max_len = i + 1;
        }
        
        if (cumulative_sum_index.find(cumulative_sum - k) != cumulative_sum_index.end()) {
            // If (cumulative_sum - k) exists in the map, update max_len
            max_len = max(max_len, i - cumulative_sum_index[cumulative_sum - k]);
        }
        
        // If cumulative_sum is not in the map, store it with its index
        if (cumulative_sum_index.find(cumulative_sum) == cumulative_sum_index.end()) {
            cumulative_sum_index[cumulative_sum] = i;
        }
    }
    
    return max_len;
}
