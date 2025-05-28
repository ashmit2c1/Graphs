#include<bits/stdc++.h>
using namespace std;

bool check(int node, int parent, vector<int>& parentarray, vector<bool>& visited, vector<vector<int>>& graph, vector<int>& path) {
    visited[node] = true;
    int n = graph[node].size();
    for (int i = 0; i < n; i++) {
        int neighbor = graph[node][i];
        if (neighbor == parent) {
            continue;
        }
        if (visited[neighbor] == true) {
            path.push_back(neighbor);
            int current = node;
            while (current != neighbor) {
                path.push_back(current);
                current = parentarray[current];
            }
            path.push_back(neighbor);
            return true;
        } else {
            parentarray[neighbor] = node;
            if (check(neighbor, node, parentarray, visited, graph, path) == true) {
                return true;
            }
        }
    }
    return false;
}

bool isCycle(vector<int>& parentarray, vector<bool>& visited, vector<int>& path, vector<vector<int>>& graph) {
    int n = visited.size();
    for (int i = 0; i < n; i++) {
        if (visited[i] == false) {
            if (check(i, -1, parentarray, visited, graph, path) == true) {
                return true;
            }
        }
    }
    return false;
}

bool solve(vector<vector<int>> graph) {
    vector<int> parent(graph.size(), -1);
    vector<bool> visited(graph.size(), false);
    vector<int> path;
    bool checkf = isCycle(parent, visited, path, graph);
    if (checkf == false) {
        return false;
    } else {
        if(path.size()%2==0){
            return true;
        }else{
            return false;
        }
    }
}
