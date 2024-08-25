int minimumDishes(int n, int m, vector<int> arr) {
    unordered_map<int, int> freq;
    
    // Count the frequency of each dish type
    for (int i = 0; i < n; ++i) {
        freq[arr[i]]++;
    }
    
    // Store the frequencies in a vector
    vector<int> frequencies;
    for (auto& f : freq) {
        frequencies.push_back(f.second);
    }
    
    // Sort frequencies in ascending order
    sort(frequencies.begin(), frequencies.end());
    
    // Cancel the orders from the least frequent types first
    int totalDishes = frequencies.size();
    for (int i = 0; i < frequencies.size(); ++i) {
        if (m >= frequencies[i]) {
            m -= frequencies[i];
            totalDishes--;
        } else {
            break;
        }
    }
    
    return totalDishes;
}
