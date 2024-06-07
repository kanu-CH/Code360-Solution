#include <bits/stdc++.h>

void setZeros(vector<vector<int>> &matrix)
{
	int n = matrix.size();
    if (n == 0) return;
    int m = matrix[0].size();
    if (m == 0) return;
    
    unordered_set<int> rows, cols;
    
    // Step 1: Identify all rows and columns that need to be zeroed
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] == 0) {
                rows.insert(i);
                cols.insert(j);
            }
        }
    }
    
    // Step 2: Set identified rows to zero
    for (int row : rows) {
        for (int j = 0; j < m; ++j) {
            matrix[row][j] = 0;
        }
    }
    
    // Step 3: Set identified columns to zero
    for (int col : cols) {
        for (int i = 0; i < n; ++i) {
            matrix[i][col] = 0;
        }
    }
}
