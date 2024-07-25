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

    // Vectors to keep track of visited nodes and their parents
    vector<int> visited(n + 1, 0);
    vector<int> parent(n + 1, -1);
    queue<int> qu;

    // BFS initialization
    qu.push(s);
    visited[s] = 1;

    // BFS loop
    while(!qu.empty()) {
        int val = qu.front();
        qu.pop();

        for(int x : adjList[val]) {
            if(visited[x] == 0) {
                visited[x] = 1;
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
