#include <bits/stdc++.h> 
bool findWord(string &s, string &w)
{
	// Split the sentence into words
    istringstream iss(s);
    string word;
    while (iss >> word) {
        // Check if the current word is equal to the word we're looking for
        if (word == w) {
            return true;
        }
    }
    return false;
}
