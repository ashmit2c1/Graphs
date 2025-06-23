#include<bits/stdc++.h>
using namespace std;

// FIND THE SHORTEST PATH FROM 1 TO N 
vector<int> shortestPath(vector<vector<int>>& roads, int n) {
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < (int)roads.size(); i++) {
        int u = roads[i][0];
        int v = roads[i][1];
        int weight = roads[i][2];
        adj[u].push_back({v, weight});
        adj[v].push_back({u,weight});
    }

    vector<int> distance(n + 1, INT_MAX);
    vector<bool> visited(n + 1, false);
    vector<int> parent(n + 1, -1);

    distance[1] = 0;

    for (int j = 1; j <= n; j++) {
        int node = -1;
        int value = INT_MAX;
        for (int i = 1; i <= n; i++) {
            if (visited[i] == false && distance[i] < value) {
                node = i;
                value = distance[i];
            }
        }

        if (node == -1) {
            break;
        }

        visited[node] = true;

        int size = adj[node].size();
        for (int i = 0; i < size; i++) {
            int neighbor = adj[node][i].first;
            int weight = adj[node][i].second;
            if (distance[neighbor] > weight + distance[node]) {
                distance[neighbor] = weight + distance[node];
                parent[neighbor] = node;
            }
        }
    }

    for (int i = 0; i < (int)distance.size(); i++) {
        if (distance[i] == INT_MAX) {
            distance[i] = -1;
        }
    }
    vector<int> ans;
    int current = n;
    if (distance[n] == -1) return {-1};

    while (current != -1) {
        ans.push_back(current);
        current = parent[current];
    }

    reverse(ans.begin(), ans.end());
    return ans;
}
int main() {
    int n = 5;
    vector<vector<int>> roads = {
{1,2,2},{2, 5, 5},{2, 3, 4},{1, 4, 1},{4, 3, 3},{3, 5, 1}
    };

    vector<int> path = shortestPath(roads, n);
    for (int node : path) cout << node << " ";
}