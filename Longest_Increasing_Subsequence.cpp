#include <bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
    if(n == 0)
        return 0;
            
    vector<int> ans;
    ans.push_back(arr[0]);
        
    for(int i=1; i<n; i++){
        if(arr[i] > ans.back())
            ans.push_back(arr[i]);
                
        else{
            // find index of just bigger element
            int index = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
            ans[index] = arr[i];
        }
    }
        
    return ans.size();
}
