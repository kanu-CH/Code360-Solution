#include <vector>

vector<int> MinimumCoins(int n) {
    vector<int> coins = {1000, 500, 100, 50, 20, 10, 5, 2, 1};
    vector<int> result;

    for (int i = 0; i < coins.size(); i++) {
        while (n >= coins[i]) {
            n -= coins[i];
            result.push_back(coins[i]);
        }
    }

    return result;
}
