#include <bits/stdc++.h> 

void posAndNeg(vector<int> &arr)
{
    vector<int> positive;
    vector<int> negative;
    
    // Separate positive and negative numbers
    for (int num : arr) {
        if (num >= 0) {
            positive.push_back(num);
        } else {
            negative.push_back(num);
        }
    }
    
    // Merge back into the original array
    int posIndex = 0, negIndex = 0, i = 0;
    
    // Place elements alternately
    while (posIndex < positive.size() && negIndex < negative.size()) {
        arr[i++] = positive[posIndex++];
        arr[i++] = negative[negIndex++];
    }
    
    // If any remaining positive or negative elements, they are added at the end.
    while (posIndex < positive.size()) {
        arr[i++] = positive[posIndex++];
    }
    
    while (negIndex < negative.size()) {
        arr[i++] = negative[negIndex++];
    }
}
