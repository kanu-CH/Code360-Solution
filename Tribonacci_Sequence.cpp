#include <bits/stdc++.h>
const long long MOD = 1e9 + 7;
int tribonacciSeq(int n) {
  if (n == 0)
    return 0;
  if (n == 1)
    return 1;
  if (n == 2)
    return 1;
  vector<long long> dp(n + 1);
  dp[0] = 0;
  dp[1] = 1;
  dp[2] = 1;
  for (int i = 3; i <= n; i++)
    dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % MOD;
  return dp[n];
}
