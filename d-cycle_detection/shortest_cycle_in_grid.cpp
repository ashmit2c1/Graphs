#include<bits/stdc++.h>
using namespace std;
void check(int node, int parent, vector<int>& parentarray, vector<bool>& visited, vector<bool>& path, vector<vector<int>>& cycles, vector<vector<int>>& adj) {
    visited[node] = true;
    path[node] = true;
    int n = adj[node].size(); 
    for (int i = 0; i < n; i++) {
        int neighbor = adj[node][i];
        if (neighbor == parent) {
            continue;
        }
        if (!visited[neighbor]) {
            parentarray[neighbor] = node;
            check(neighbor, node, parentarray, visited, path, cycles, adj);
        } else if (path[neighbor]) { 
            vector<int> cycle;
            cycle.push_back(neighbor);
            int current = node;
            while (current != neighbor) {
                cycle.push_back(current);
                current = parentarray[current];
            }
            cycle.push_back(neighbor);
            cycles.push_back(cycle);
        }
    }
    
    path[node] = false;
}
void findcycles(int n, vector<int>& parentarray, vector<bool>& visited, vector<bool>& path, vector<vector<int>>& cycles, vector<vector<int>>& adj) {
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            check(i, -1, parentarray, visited, path, cycles, adj);
        }
    }
}
int minCycleLength(vector<int>& edges) {
    int n = edges.size();
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
        if (edges[i] != -1) {
            adj[i].push_back(edges[i]);
        }
    }
    vector<int> parentarray(n, -1);
    vector<bool> visited(n, false);
    vector<bool> path(n, false);
    vector<vector<int>> cycles;
    findcycles(n, parentarray, visited, path, cycles, adj);
    int minlen = INT_MAX;
    for (const auto& cycle : cycles) {
        minlen = min(minlen, (int)cycle.size());
    }
    return minlen == INT_MAX ? -1 : minlen; 
}
