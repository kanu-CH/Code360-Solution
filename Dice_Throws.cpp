#include <bits/stdc++.h>
int solve(int d, int f, int t){
    const int MOD = 1e9 + 7;
    vector<int> prev(t+1, 0);
    vector<int> curr(t+1, 0);
        
    prev[0] = 1;
        
    for(int dice = 1; dice <= d; dice++){
        for(int target = 1; target <= t; target++){
            int ans = 0;
            for(int i=1; i<=f; i++){
                if(target-i >= 0)
                    ans = (ans + prev[target - i]) % MOD;
            }
            curr[target] = ans;
        }  
        prev = curr;
    }
    return prev[t];
}
int diceThrows(int d, int f, int s) {
    return solve(d, f, s);
}
