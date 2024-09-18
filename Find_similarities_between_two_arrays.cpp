#include <bits/stdc++.h> 
pair < int , int > findSimilarity(vector < int > arr1, vector < int > arr2, int n, int m) 
{
	set<int> set1(arr1.begin(), arr1.end()); // Store elements of ARR1
    set<int> unionSet;  // To store the union of ARR1 and ARR2
    int commonCount = 0;

    // Find common elements and build the union set
    for (int i = 0; i < m; ++i) {
        if (set1.find(arr2[i]) != set1.end()) {
            ++commonCount; // If arr2[i] is found in set1, it's a common element
        }
        unionSet.insert(arr2[i]); // Insert arr2[i] in the union set
    }

    // Insert all elements of ARR1 in the union set
    unionSet.insert(arr1.begin(), arr1.end());

    // Return the number of common elements and the size of the union set
    return {commonCount, (int)unionSet.size()};

}
