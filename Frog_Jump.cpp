#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &heights)
{
    if (n == 1) return 0;
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;
    dp[1] = abs(heights[1] - heights[0]);
    
    for (int i = 2; i < n; ++i) {
        dp[i] = min(dp[i-1] + abs(heights[i] - heights[i-1]), dp[i-2] + abs(heights[i] - heights[i-2]));
    }
    return dp[n-1];
}
