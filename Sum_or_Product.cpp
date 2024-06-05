#include <bits/stdc++.h> 
const long long MOD = 1000000007;
long long int sumOrProduct(long long int n, long long int q)
{
	if (q == 1) {
        // Calculate sum of first n natural numbers
        return (n * (n + 1)) / 2;
    } else if (q == 2) {
        // Calculate product of first n natural numbers modulo 10^9 + 7
        long long product = 1;
        for (long long i = 1; i <= n; i++) {
            product = (product * i) % MOD;
        }
        return product;
    }
    return 0;
}
