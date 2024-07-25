#include <bits/stdc++.h>

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	// Creating adjacency list
    unordered_map<int, list<int>> adjList;
    for(int i = 0; i < m; i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // Maps to keep track of visited nodes and their parents
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    queue<int> qu;

    // BFS initialization
    qu.push(s);
    visited[s] = true;
    parent[s] = -1;

    // BFS loop
    while(!qu.empty()) {
        int val = qu.front();
        qu.pop();

        for(int x : adjList[val]) {
            if(!visited[x]) {
                visited[x] = true;
                parent[x] = val;
                qu.push(x);
            }
        }
    }

    // Constructing the shortest path
    vector<int> solution;
    int current = t;
    while(current != -1) {
        solution.push_back(current);
        current = parent[current];
    }

    // Reverse the solution to get the path from S to T
    reverse(solution.begin(), solution.end());

    return solution;
}
