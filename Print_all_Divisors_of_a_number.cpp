int* printDivisors(int n, int &size){
    vector<int> divisors;
    
    // Iterate from 1 to the square root of n
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            divisors.push_back(i);          // Add i
            if (i != n / i) {
                divisors.push_back(n / i);  // Add n/i if it's different from i
            }
        }
    }
    
    // Sort the divisors
    sort(divisors.begin(), divisors.end());
    
    // Allocate memory for the result array
    size = divisors.size();
    int* result = new int[size];
    
    // Copy divisors into the result array
    for (int i = 0; i < size; i++) {
        result[i] = divisors[i];
    }
    
    return result;
}
