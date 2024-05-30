#include <bits/stdc++.h> 
#include <iostream>

using namespace std;

int countBits(int n) {
    int count = 0;
    while (n > 0) {
        // Check if the least significant bit is 1
        if (n & 1) {
            count++;
        }
        // Right shift n by 1 to process the next bit
        n >>= 1;
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    cout<<countBits(n);
    return 0;
}
