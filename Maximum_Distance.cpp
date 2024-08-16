#include <bits/stdc++.h> 
int maxDiff(vector<int> &A, int n)
{
    vector<int> leftMin(n), rightMax(n);

    // Fill leftMin array
    leftMin[0] = A[0];
    for (int i = 1; i < n; i++) {
        leftMin[i] = min(A[i], leftMin[i - 1]);
    }

    // Fill rightMax array
    rightMax[n - 1] = A[n - 1];
    for (int j = n - 2; j >= 0; j--) {
        rightMax[j] = max(A[j], rightMax[j + 1]);
    }

    // Traverse both arrays to find the maximum j - i
    int i = 0, j = 0, maxDiff = 0;
    while (j < n && i < n) {
        if (leftMin[i] <= rightMax[j]) {
            maxDiff = max(maxDiff, j - i);
            j++
        } else {
            i++;
        }
    }

    return maxDiff;
}
