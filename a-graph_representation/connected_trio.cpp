#include <bits/stdc++.h>
using namespace std;
// MIN TRIO DEGREE
int minTrioDegree(int n, vector<vector<int>>& edges) {
    vector<int> degree(n + 1, 0);
    vector<unordered_set<int>> list(n + 1);
    for (const auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        degree[u]++;
        degree[v]++;
        list[u].insert(v);
        list[v].insert(u);
    }
    int min_degree = INT_MAX;
    for (int u = 1; u <= n; u++) {
        for (int v : list[u]) {
            if (v <= u) continue;
            for (int w : list[v]) {
                if (w <= v) continue;
                if (list[u].count(w)) { 
                    int trio_degree = degree[u] + degree[v] + degree[w] - 6;
                    min_degree = min(min_degree, trio_degree);
                }
            }
        }
    }
    return (min_degree == INT_MAX) ? -1 : min_degree;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(m);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        edges[i] = {u, v}; 
    }
    int ans = minTrioDegree(n, edges);
    cout << ans << "\n";
    return 0;
}