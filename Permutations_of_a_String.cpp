#include <bits/stdc++.h>
void permutations(int idx, string& str, vector<string>& ans) {
        if (idx >= str.size()) {
            ans.push_back(str);
            return;
        }
        for (int i = idx; i < str.size(); i++) {
            swap(str[idx], str[i]);
            permutations(idx+1, str, ans);
            swap(str[idx], str[i]);
        }
}
vector<string> generatePermutations(string &str)
{
    vector<string> ans;
    permutations(0, str, ans);
    sort(ans.begin(), ans.end());
    return ans;
}
