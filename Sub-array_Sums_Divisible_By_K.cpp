#include <bits/stdc++.h> 
int subArraySumDivisibleByK(vector<int> &arr, int n, int k)
{
	// Result will store the total number of subarrays whose sum is divisible by k 
	int result = 0;
	
	// StoreMod will store the count of every remainder
	vector<int> storeMod(k);
    storeMod[0] = 1;
    
    int rem = 0;
    for (int i = 0; i < n; i += 1) 
    {
        rem = (rem + arr[i] % k + k) % k;
        
        // Updating the result
        result += storeMod[rem];
        
        // Updating the count of 'rem' in 'storeMod'
        storeMod[rem] += 1;
    }
	
    return result;
}
