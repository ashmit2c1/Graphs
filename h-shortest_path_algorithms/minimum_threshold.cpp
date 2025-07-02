#include<bits/stdc++.h>
using namespace std;
// CITIES WITH MINIMUM THRESHOLD DISTANCE 

class Solution {
public:
    vector<int> findDist(int n, int src, vector<vector<pair<int, int>>>& adj) {
        vector<int> distance(n, INT_MAX);
        distance[src] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
        pq.push({0, src});
        while (!pq.empty()) {
            int node = pq.top().second;
            int cost = pq.top().first;
            pq.pop();
            for (auto& neighbor : adj[node]) {
                int next = neighbor.first;
                int wt = neighbor.second;
                if (distance[next] > cost + wt) {
                    distance[next] = cost + wt;
                    pq.push({distance[next], next});
                }
            }
        }
        return distance;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], wt = edge[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        vector<int> reachable(n);
        for (int i = 0; i < n; i++) {
            vector<int> dist = findDist(n, i, adj);
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && dist[j] <= distanceThreshold) {
                    count++;
                }
            }
            reachable[i] = count;
        }

        int minReach = INT_MAX;
        int result = -1;
        for (int i = n - 1; i >= 0; i--) {
            if (reachable[i] < minReach) {
                minReach = reachable[i];
                result = i;
            }
        }
        return result;
    }
};
// SOLVING IT USING FLOYD WARSHALL ALGORITHM 
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        const int INF = 1e9;
        vector<vector<int>> dist(n, vector<int>(n, INF));

        for (int i = 0; i < n; ++i) dist[i][i] = 0;

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            dist[u][v] = w;
            dist[v][u] = w;
        }

        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        // Separate logic: Count how many cities are reachable from each city
        vector<int> reachableCount(n, 0);
        for (int i = 0; i < n; ++i) {
            int count = 0;
            for (int j = 0; j < n; ++j) {
                if (i != j && dist[i][j] <= distanceThreshold) {
                    count++;
                }
            }
            reachableCount[i] = count;
        }

        int minCity = -1, minCount = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (reachableCount[i] <= minCount) {
                minCount = reachableCount[i];
                minCity = i;
            }
        }

        return minCity;
    }
};