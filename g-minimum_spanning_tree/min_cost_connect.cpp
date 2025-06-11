#include<bits/stdc++.h>
using namespace std;

int minCostConnectPoints(vector<vector<int>>& points) {
    int n = points.size();
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < n; i++) {
        int originalX = points[i][0];
        int originalY = points[i][1];
        vector<pair<int, int>> temp;
        for (int j = 0; j < n; j++) {
            int destinationX = points[j][0];
            int destinationY = points[j][1];
            int weight = abs(destinationX - originalX) + abs(destinationY - originalY);
            temp.push_back({j, weight});
        }
        adj[i] = temp;
    }

    vector<int> isMST(n, false);
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<int> parent(n, -1);
    pq.push({0, {0, -1}});
    int cost = 0;

    while (pq.empty() == false) {
        int weight = pq.top().first;
        int node = pq.top().second.first;
        int par = pq.top().second.second;
        pq.pop();

        if (isMST[node] == false) {
            isMST[node] = true;
            parent[node] = par;
            cost += weight;

            int m = adj[node].size();
            for (int i = 0; i < m; i++) {
                int adjNode = adj[node][i].first;
                int adjWeight = adj[node][i].second;

                if (isMST[adjNode] == false) {
                    pq.push({adjWeight, {adjNode, node}});
                }
            }
        }
    }
    return cost;
}
