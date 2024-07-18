//using dfs

#include <bits/stdc++.h> 

void topoSort(int node, vector<bool> &visited, stack<int> &st, unordered_map<int, list<int>> &adj) {
    visited[node] = 1;

    for (auto neighbour : adj[node]) {
        if (!visited[neighbour]) {
            topoSort(neighbour, visited, st, adj);
        }
    }
    st.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // adjacency list
    unordered_map<int, list<int>> adj;

    for (int i=0; i<edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    vector<bool> visited(v);
    stack<int> st;

    for (int i=0; i<v; i++) {
        if (!visited[i]) {
            topoSort(i, visited, st, adj);
        }
    }

    vector<int> ans;

    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}


//using bfs (Kahn's algorithm)

#include <bits/stdc++.h> 

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // adjacency list
    unordered_map<int, list<int>> adj;

    for (int i=0; i<edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    // finding indgrees of vertices
    vector<int> indegree(v);
    for (auto i : adj) {
        for (auto j : i.second) {
            indegree[j]++;
        }
    }

    queue<int> q;
    
    // pushing vertices having 0 indegree
    for (int i=0; i<indegree.size(); i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> ans;

    while (!q.empty()) {
        int front = q.front();
        q.pop();

        ans.push_back(front);

        for (auto neighbour : adj[front]) {
            indegree[neighbour]--;

            if (indegree[neighbour] == 0) {
                q.push(neighbour);
            }
        }
    }

    return ans;
}
