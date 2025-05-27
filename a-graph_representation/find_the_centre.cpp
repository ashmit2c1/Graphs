#include <bits/stdc++.h>
using namespace std;
// FIND THE CENTRE OF STAR GRAPH

int findCentre(vector<vector<int>>& edges) {
    int nodes = edges.size() + 1;
    vector<int> indegree(nodes, 0);
    vector<int> outdegree(nodes, 0);
    for (int i = 0; i < edges.size(); i++) {
        int source = edges[i][0];
        int destination = edges[i][1];
        indegree[source]++;
        indegree[destination]++;
        outdegree[source]++;
        outdegree[destination]++;
    }
    for (int i = 0; i < nodes; i++) {
        if (indegree[i] == nodes - 1 && outdegree[i] == nodes - 1) {
            return i;
        }
    }
    return -1;
}
int main() {
    int n;
    cin >> n;
    vector<vector<int>> edges(n - 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        edges[i] = {u - 1, v - 1}; 
    }
    int ans = findCentre(edges);
    cout << ans + 1 << "\n"; 
    return 0;
}
