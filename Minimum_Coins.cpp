#include <bits/stdc++.h> 
int minimumCoins(int p)
{
    vector<int> coins = {1000, 500, 100, 50, 20, 10, 5, 2, 1};
    int count = 0;

    for (int i = 0; i < coins.size(); i++) {
        if (p == 0) break;
        count += p / coins[i];
        p %= coins[i];
    }

    return count;
}
