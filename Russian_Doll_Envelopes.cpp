#include <vector>
#include <algorithm>

int findMaxEnvelopes(vector<int> &height, vector<int> &width, int n) {
    
    vector<pair<int, int>> envelopes(n);
    
    // Pair the height and width and store them
    for (int i = 0; i < n; i++) {
        envelopes[i] = {height[i], width[i]};
    }
    
    // Sort by height, and by width in descending order if heights are the same
    sort(envelopes.begin(), envelopes.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
        if (a.first == b.first)
            return a.second > b.second;
        return a.first < b.first;
    });
    
    // Now find the LIS based on width
    vector<int> lis;
    for (int i = 0; i < n; i++) {
        int currentWidth = envelopes[i].second;
        auto it = lower_bound(lis.begin(), lis.end(), currentWidth);
        if (it == lis.end()) {
            lis.push_back(currentWidth);
        } else {
            *it = currentWidth;
        }
    }
    
    // The size of lis will be our answer
    return lis.size();
}
