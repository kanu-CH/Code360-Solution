#include <bits/stdc++.h> 
const int MOD = 1e9 + 7;
int countDistinctWays(int nStairs) {
    if (nStairs == 0) return 1;
    if (nStairs == 1) return 1;

    vector<long long> dp(nStairs + 1);
    dp[0] = 1;
    dp[1] = 1;
    
    for (int i = 2; i <= nStairs; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }
    
    return dp[nStairs];
}
