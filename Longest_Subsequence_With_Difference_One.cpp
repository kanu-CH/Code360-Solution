#include <bits/stdc++.h> 
int longestSubsequence(vector<int> &nums){
	int n = nums.size();
    vector<int> dp(n, 1); // Initialize dp array with 1 (every element itself is a subsequence)
    
    int longest = 1; // At least one element subsequence
    
    // Loop through each element
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (abs(nums[i] - nums[j]) == 1) {
                dp[i] = max(dp[i], dp[j] + 1); // Extend subsequence
            }
        }
        longest = max(longest, dp[i]); // Update longest subsequence length
    }
    
    return longest;
}
