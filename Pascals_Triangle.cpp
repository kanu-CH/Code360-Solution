#include <bits/stdc++.h>

vector<vector<long long int>> printPascal(int n) 
{
  vector<vector<long long int>> pascalTriangle;

  // The first row is always [1]
  pascalTriangle.push_back({1});

  // Generate each row from the second to the nth
  for (int i = 1; i < n; ++i) {
    vector<long long int> row;
    row.push_back(1); // The first element is always 1

    // Calculate the intermediate elements
    for (int j = 1; j < i; ++j) {
      row.push_back(pascalTriangle[i-1][j-1] + pascalTriangle[i-1][j]);
    }

    row.push_back(1); // The last element is always 1
    pascalTriangle.push_back(row);
  }

  return pascalTriangle;
}
