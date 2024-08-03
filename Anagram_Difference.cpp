#include <bits/stdc++.h> 
int getMinimumAnagramDifference(string &str1, string &str2) {
    // Frequency arrays for characters in s and t
    vector<int> countStr1(26, 0);
    vector<int> countStr2(26, 0);

    // Count characters in s
    for (char c : str1) {
        countStr2[c - 'a']++;
    }

    // Count characters in t
    for (char c : str2) {
        countStr1[c - 'a']++;
    }

    // Calculate the number of replacements needed
    int steps = 0;
    for (int i = 0; i < 26; i++) {
        if (countStr1[i] > countStr2[i]) {
            steps += countStr1[i] - countStr2[i];
        }
    }

    return steps;
}
