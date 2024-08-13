long countWaysToMakeChange(int *denominations, int n, int value)
{
    // Create a DP array to store the number of ways to make each value up to `value`
    long *dp = new long[value + 1]();
    dp[0] = 1; // There's one way to make 0, by using no coins

    // Update the dp array for each denomination
    for (int i = 0; i < n; i++) {
        for (int j = denominations[i]; j <= value; j++) {
            dp[j] += dp[j - denominations[i]];
        }
    }

    long result = dp[value];
    delete[] dp; // Clean up the dynamically allocated memory
    return result;
}
