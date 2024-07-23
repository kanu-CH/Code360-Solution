#include <bits/stdc++.h> 
vector<int> findFrequency(string S) {
	vector<int> freq(26, 0);  // Initialize a vector of size 26 with 0s

    // Count frequencies of each character
    for (char c : S) {
        freq[c - 'a']++;  // Increment the count for the character
    }

    return freq;
}
