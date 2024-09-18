#include <bits/stdc++.h> 
vector<int> separateNegativeAndPositive(vector<int> &nums){
    // vector<int> neg, pos;
    // int n = nums.size();
    // for(int i=0; i<n; i++){
    //     if(nums[i]<0)
    //         neg.push_back(nums[i]);
    //     else
    //         pos.push_back(nums[i]);
    // }
    // for(int i=0; i<neg.size(); i++){
    //     nums[i] = neg[i];
    // }
    // for(int i=neg.size(),j=0; i<n; i++,j++){
    //     nums[i] = pos[j];
    // }
    // return nums;


    // In-place rearrangement
    int left = 0;
    
    for (int right = 0; right < nums.size(); ++right) {
        if (nums[right] < 0) {
            swap(nums[left], nums[right]);
            ++left;
        }
    }
    
    return nums;
}
