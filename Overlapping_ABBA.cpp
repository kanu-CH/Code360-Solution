bool findOverlap(string &s){
    int n = s.length();
    
    bool foundAB = false;
    bool foundBA = false;

    // Search for "AB" followed by "BA"
    for (int i = 0; i < n - 1; ++i) {
        if (!foundAB && s[i] == 'A' && s[i + 1] == 'B') {
            foundAB = true;
            i += 1; // Move i to the end of "AB"
        } else if (foundAB && s[i] == 'B' && s[i + 1] == 'A') {
            return true;
        }
    }
    
    // Reset and search for "BA" followed by "AB"
    foundAB = false;
    for (int i = 0; i < n - 1; ++i) {
        if (!foundBA && s[i] == 'B' && s[i + 1] == 'A') {
            foundBA = true;
            i += 1; // Move i to the end of "BA"
        } else if (foundBA && s[i] == 'A' && s[i + 1] == 'B') {
            return true;
        }
    }
    
    return false;
}
