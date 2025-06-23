#include<bits/stdc++.h>
using namespace std;

// NETWORK DELAY TIME 
int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<vector<pair<int, int>>> adj(n + 1);
    vector<int> distance(n + 1, INT_MAX);
    vector<bool> visited(n + 1, false);
    for (int i = 0; i < (int)times.size(); i++) {
        int u = times[i][0];
        int v = times[i][1];
        int weight = times[i][2];
        adj[u].push_back({v, weight});
    }
    distance[k] = 0;
    for (int j = 1; j <= n; j++) {
        int node = -1;
        int value = INT_MAX;
        for (int i = 1; i <= n; i++) {
            if (!visited[i] && distance[i] < value) {
                node = i;
                value = distance[i];
            }
        }
        if (node == -1) break;
        visited[node] = true;
        int size = adj[node].size();
        for (int i = 0; i < size; i++) {
            int neighbor = adj[node][i].first;
            int weight = adj[node][i].second;
            if (distance[neighbor] > distance[node] + weight) {
                distance[neighbor] = distance[node] + weight;
            }
        }
    }
    int maxTime = 0;
    for (int i = 1; i <= n; i++) {
        if (distance[i] == INT_MAX) return -1;
        maxTime = max(maxTime, distance[i]);
    }

    return maxTime;
}
