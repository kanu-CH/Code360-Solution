#include <bits/stdc++.h> 
int ninjaComplement(int n) 
{
	if (n == 0) return 1;
    unsigned int mask = ~0;
    while (n & mask) {
        mask <<= 1;
    }
    return ~mask & ~n;
}
