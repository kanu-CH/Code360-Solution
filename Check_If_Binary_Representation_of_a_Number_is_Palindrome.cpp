#include <bits/stdc++.h> 
bool isKthBitSet(long long x, int k)
{
    return ((x & (1LL << (k - 1))) >= 1) ? true : false;
}
bool checkPalindrome(long long N)
{
    int l = 1;
    long long temp = N;
    int r = log2(N) + 1;
    while (l < r)
    {
        if (isKthBitSet(N, l++) != isKthBitSet(N, r--))
        {
            return false;
        }
    }
    return true;
}
