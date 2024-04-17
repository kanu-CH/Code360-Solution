#include <bits/stdc++.h> 
vector<int> firstNegativeInteger(vector<int> &arr, int k, int n)
{
    deque<int> dq;
    vector<int> ans;
    int negative = -1;
         
    //process first window
    for(int i=0; i<k; i++) {
        if(arr[i] < 0) {
            dq.push_back(i);
        }
    }
         
    //push ans for FIRST window
    if(dq.size() > 0) {
        ans.push_back(arr[dq.front()]);
    }
    else{
        ans.push_back(0);
    }
         
    //now process for remaining windows
    for(int i = k; i<n; i++) {
        //first pop out of window element
        if(!dq.empty() && (i - dq.front())>=k ) {
            dq.pop_front();
        }
             
        //then push current element
        if(arr[i] < 0)
            dq.push_back(i);
        // put in ans
        if(dq.size() > 0) {
            ans.push_back(arr[dq.front()]);
        }
        else{
            ans.push_back(0);
        }
    }
    return ans;
}
