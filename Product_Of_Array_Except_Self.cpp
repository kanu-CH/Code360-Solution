#include <iostream>
#include <vector>
#define MOD 1000000007

int *getProductArrayExceptSelf(int *arr, int n)
{
    if (n == 0) return NULL;

    int* product = new int[n];
    vector<long long> left_product(n, 1);
    vector<long long> right_product(n, 1);

    // Calculate left_product
    for (int i = 1; i < n; ++i) {
        left_product[i] = (left_product[i - 1] * arr[i - 1]) % MOD;
    }

    // Calculate right_product
    for (int i = n - 2; i >= 0; --i) {
        right_product[i] = (right_product[i + 1] * arr[i + 1]) % MOD;
    }

    // Calculate product array
    for (int i = 0; i < n; ++i) {
        product[i] = (left_product[i] * right_product[i]) % MOD;
    }

    return product;
}
