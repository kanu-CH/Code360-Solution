#include <bits/stdc++.h> 
#include <iostream>

using namespace std;

// Function to generate all prime numbers up to `max_val` using Sieve of Eratosthenes
vector<bool> sieveOfEratosthenes(int max_val) {
    vector<bool> is_prime(max_val + 1, true);
    is_prime[0] = is_prime[1] = false; // 0 and 1 are not prime numbers
    for (int i = 2; i <= sqrt(max_val); i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= max_val; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}

// Function to count the total number of primes in the interval [S, E]
int totalPrime(int S, int E) {
    if (S > E) return 0; // Handle edge case where S is greater than E
    vector<bool> is_prime = sieveOfEratosthenes(E);
    int prime_count = 0;
    for (int i = max(S, 2); i <= E; i++) { // Ensure we start counting from the maximum of S or 2
        if (is_prime[i]) {
            prime_count++;
        }
    }
    return prime_count;
}

int main() {
    int S, E;
    cin >> S >> E;
    cout << totalPrime(S, E);
    return 0;
}
