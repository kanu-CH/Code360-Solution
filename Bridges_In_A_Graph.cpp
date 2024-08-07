#include <bits/stdc++.h>

void dfs(int node, int parent, int &timer, vector<int> &disc,
    vector<int> &low, vector<vector<int>> &result,
    unordered_map<int, list<int>> &adjList, vector<bool> &visited) {

    visited[node] = true;
    disc[node] = low[node] = timer++;

    for(auto neigh : adjList[node]) {
        if(neigh == parent) continue;

        if(visited[neigh] == false) {
            dfs(neigh, node, timer, disc, low, result, adjList, visited);
            low[node] = min(low[node], low[neigh]);

            // Check bridge edge
            if(low[neigh] > disc[node]) {
                result.push_back({node, neigh});
            }
        } else {
            // Back edge found
            low[node] = min(low[node], disc[neigh]);
        }
    }
}
vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    // Create adjList
    unordered_map<int, list<int>> adjList;
    for(int i=0; i<e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u); 
    }

    int timer = 0;
    vector<int> disc(v, -1);
    vector<int> low(v, -1);
    int parent = -1;
    vector<bool> visited(v, false);
    vector<vector<int>> result;

    // DFS
    for(int i=0; i<v; i++) {
        if(!visited[i]) {
            dfs(i, parent, timer, disc, low, result, adjList, visited);
        }
    }

    return result;

}
