#include <bits/stdc++.h> 
#define MOD 1000000007

int add(int a , int b){
    return (a%MOD + b%MOD)%MOD; 
}
int mul(int a, int b){
    return ((a%MOD)*1LL*(b%MOD))%MOD;
}
int countWays(int n)
{
    int prev2 = 2; 
    int prev1 = 4; 

    for (int i = 3; i <= n; i++) {
        int curr = add(mul(prev1, 1), mul(prev2, 1));
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}
