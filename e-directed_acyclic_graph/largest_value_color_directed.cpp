#include<bits/stdc++.h>
using namespace std;
// BRUTE FORCE SOLUTION
// first check if there is any cycle 
// store the index -> char map
// find all paths
// store char -> index -> map
// find the largest val 
void dfs(int node, vector<vector<int>>& adj, vector<int>& path,
         vector<vector<int>>& allPaths, vector<bool>& visited) {
    visited[node] = true;
    path.push_back(node);

    if (adj[node].empty()) {
        allPaths.push_back(path);
    } else {
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, path, allPaths, visited);
            }
        }
    }

    path.pop_back();
    visited[node] = false;
}
bool hasCycle(int n, vector<vector<int>>& adj) {
    vector<int> indegree(n, 0);
    for (int i = 0; i < n; ++i) {
        for (int neighbor : adj[i]) {
            indegree[neighbor]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (indegree[i] == 0) q.push(i);
    }
    int count = 0;
    while (!q.empty()) {
        int node = q.front(); q.pop(); count++;
        for (int neighbor : adj[node]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }
    return count != n;
}
int largestPathValue(string colors, vector<vector<int>>& edges) {
    int n = colors.size();
    vector<vector<int>> adj(n);
    for (auto& edge : edges) {
        adj[edge[0]].push_back(edge[1]);
    }
    if (hasCycle(n, adj)) return -1;
    vector<vector<int>> allPaths;
    for (int i = 0; i < n; ++i) {
        vector<int> path;
        vector<bool> visited(n, false);
        dfs(i, adj, path, allPaths, visited);
    }
    int maxVal = 0;
    for (auto& path : allPaths) {
        unordered_map<char, int> colorFreq;
        for (int node : path) {
            colorFreq[colors[node]]++;
        }
        for (auto& p : colorFreq) {
            maxVal = max(maxVal, p.second);
        }
    }
    return maxVal;
}
