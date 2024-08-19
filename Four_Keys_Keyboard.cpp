#include <bits/stdc++.h> 
long long findMaxAs(int n) {
    if (n <= 6) return n;  // If N <= 6, the best we can do is just press 'A' N times
    
    vector<long long> dp(n + 1);
    
    // Initialize the first 6 values (direct presses of 'A')
    for (int i = 1; i <= 6; i++) {
        dp[i] = i;
    }
    
    // Fill the dp array using the optimal strategy
    for (int i = 7; i <= n; i++) {
        dp[i] = 0;
        for (int j = i - 3; j >= 1; j--) {
            dp[i] = max(dp[i], dp[j] * (i - j - 1));
        }
    }
    
    return dp[n];
}
