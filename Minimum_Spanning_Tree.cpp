#include <bits/stdc++.h>
bool compare(vector<int> &a, vector<int> &b) {
  return a[2] < b[2];
}

int findParent(vector<int> &parent, int node) {
  // Reached topmost point of hierarchy
  if(parent[node] == node) {
    return node;
  }
  return parent[node] = findParent(parent, parent[node]);
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank) {
  u = findParent(parent, u);
  v = findParent(parent, v);

  if(rank[u] < rank[v]) {
    parent[u] = v;
  } 
  else if(rank[v] < rank[u]) {
    parent[v] = u;
  } 
  else {
    parent[v] = u;
    rank[u]++;
  }
}

int minimumSpanningTree(vector<vector<int>> &edges, int n) {
  // Sorting vector according to their weight
  sort(edges.begin(), edges.end(), compare);
  vector<int> parent(n);
  vector<int> rank(n);

  // Initialising parent & rank
  for(int i=0; i<n; i++) {
    parent[i] = i;
    rank[i] = 0;
  }

  // Answer variable used to sum up the weights of nodes added in MST
  int minWeight = 0;

  for(int i=0; i<edges.size(); i++) {
    int u = findParent(parent, edges[i][0]);
    int v = findParent(parent, edges[i][1]);

    if(u != v) {
      unionSet(u, v, parent, rank);
      minWeight += edges[i][2];
      }
  }

  return minWeight;
}
