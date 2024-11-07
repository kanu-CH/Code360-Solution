#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    int i = n - 2;

    // Step 1: Find the first decreasing element from the end
    while (i >= 0 && permutation[i] >= permutation[i + 1]) {
        i--;
    }

    if (i >= 0) {  // If there is a decreasing element
        int j = n - 1;
        // Step 2: Find the next larger element to swap with
        while (permutation[j] <= permutation[i]) {
            j--;
        }
        swap(permutation[i], permutation[j]);
    }

    // Step 3: Reverse the elements after the swapped element
    reverse(permutation.begin() + i + 1, permutation.end());

    return permutation;
}
