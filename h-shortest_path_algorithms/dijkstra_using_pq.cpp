#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstraPQ(vector<vector<int>>& edges, int V) {
    vector<vector<pair<int, int>>> adj(V);
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];
        adj[u].push_back({v, weight});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});  
    vector<int> distance(V, INT_MAX);
    distance[0] = 0;
    while (!pq.empty()) {
        int node = pq.top().second; 
        int cost = pq.top().first; 
        pq.pop();
        for (auto& neighbor : adj[node]) {
            int nextNode = neighbor.first;
            int weight = neighbor.second;
            if (cost + weight < distance[nextNode]) {
                distance[nextNode] = cost + weight;
                pq.push({distance[nextNode], nextNode});
            }
        }
    }
    for (int i = 0; i < distance.size(); i++) {
        if (distance[i] == INT_MAX) {
            distance[i] = -1;
        }
    }
    return distance;
}
