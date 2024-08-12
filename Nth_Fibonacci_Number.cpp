//using dp
#include<bits/stdc++.h>
using namespace std;

//top down approch
// int fib(int n, vector<int> &dp){
//         if(n<=1)
//                 return n;
//         if(dp[n] != -1)
//                 return dp[n];
//         dp[n] = fib(n-1, dp) + fib(n-2, dp);
//         return dp[n];
// }
// int main()
// {
//         int n;
//         cin>> n;
//         vector<int> dp(n+1);
//         for(int i=0; i<=n; i++)
//                 dp[i] = -1;
//         cout << fib(n, dp) << endl;
//         return 0;
// }

//bottom up approach
int main()
{
        int n;
        cin>> n;
        vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = 1;
        for(int i=2; i<=n; i++)
                dp[i] = dp[i-1] + dp[i-2];
        cout << dp[n] << endl;
        return 0;
}
