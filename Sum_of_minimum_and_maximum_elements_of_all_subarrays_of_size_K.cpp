#include <bits/stdc++.h> 
long long sumOfMaxAndMin(vector<int> &nums, int n, int k) {
	long long sum = 0;  // Initialize result
 
    // The queue will store indexes of useful elements in every window
    // In deque 'G' we maintain decreasing order of values from front to rear
    // In deque 'S' we  maintain increasing order of values from front to rear
    deque<long long> S(k), G(k);
 
    // Process first window of size K
    int i = 0;
    for (i = 0; i < k; i++)
    {
        // Remove all previous greater elements that are useless.
        while ( (!S.empty()) && nums[S.back()] >= nums[i])
            S.pop_back(); // Remove from rear
 
        // Remove all previous smaller that are elements are useless.
        while ( (!G.empty()) && nums[G.back()] <= nums[i])
            G.pop_back(); // Remove from rear
 
        // Add current element at rear of both deque
        G.push_back(i);
        S.push_back(i);
    }
 
    // Process rest of the array elements
    for (  ; i < n; i++ )
    {
        // Element at the front of the deque 'G' & 'S' is the largest and smallest element of previous window respectively
        sum += nums[S.front()] + nums[G.front()];
 
        // Remove all elements which are out of this window
        while ( !S.empty() && S.front() <= i - k)
            S.pop_front();
        while ( !G.empty() && G.front() <= i - k)
            G.pop_front();
 
        // remove all previous greater element that are useless
        while ( (!S.empty()) && nums[S.back()] >= nums[i])
            S.pop_back(); // Remove from rear
 
        // remove all previous smaller that are elements are useless
        while ( (!G.empty()) && nums[G.back()] <= nums[i])
            G.pop_back(); // Remove from rear
 
        // Add current element at rear of both deque
        G.push_back(i);
        S.push_back(i);
    }
 
    // Sum of minimum and maximum element of last window
    sum += nums[S.front()] + nums[G.front()];
 
    return sum;
}
