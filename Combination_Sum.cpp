#include <bits/stdc++.h>
void findCombination(int ind, int target, vector<int> &arr, vector<vector<int>>& ans, vector<int>& ds) {
    if (target == 0) {
        ans.push_back(ds);
        return;
    }
    for (int i = ind; i < arr.size(); i++) {
        if (i > ind && arr[i] == arr[i - 1])
            continue; // skip duplicates
        if (arr[i] > target)
            break; // no point in exploring further as the array is sorted
        ds.push_back(arr[i]);
        findCombination(i, target - arr[i], arr, ans, ds); // not i + 1 because we can reuse same element
        ds.pop_back(); // backtrack
    }
}

vector<vector<int>> combSum(vector<int> &ARR, int B) {
    sort(ARR.begin(), ARR.end());
    vector<vector<int>> ans;
    vector<int> ds;
    findCombination(0, B, ARR, ans, ds);
    return ans;
}
