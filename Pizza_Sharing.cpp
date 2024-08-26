int solve(int start, int end, int n, vector<int> &slices) {
    vector<int> prev(n/3 + 1, 0);
    vector<int> curr(n/3 + 1, 0);
    vector<int> next(n/3 + 1, 0);
    
    for(int index = end; index >= start; index--) {
        for(int k = 1; k <= n/3; k++) {
            int take = slices[index] + next[k-1];
            int notTake = curr[k];
            prev[k] = max(take, notTake);
        }
        next = curr;
        curr = prev;
    }
    return curr[n/3];
}

int pizzaSharing(int n, vector<int> &arr) {
    // Case 1: Ninja starts picking from the first slice (skip the last slice)
    int case1 = solve(0, n-2, n, arr);
    
    // Case 2: Ninja starts picking from the second slice (skip the first slice)
    int case2 = solve(1, n-1, n, arr);
    
    return max(case1, case2);
}
