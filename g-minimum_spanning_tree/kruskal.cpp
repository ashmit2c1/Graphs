#include<bits/stdc++.h>
using namespace std;

int findParent(int node, vector<int>& parent) {
    if (parent[node] == node) return node;
    return parent[node] = findParent(parent[node], parent);
}

void unionBySize(int u, int v, vector<int>& parent, vector<int>& size) {
    int parentU = findParent(u, parent);
    int parentV = findParent(v, parent);

    if (parentU == parentV) return;

    if (size[parentU] < size[parentV]) {
        parent[parentU] = parentV;
        size[parentV] += size[parentU];
    } else {
        parent[parentV] = parentU;
        size[parentU] += size[parentV];
    }
}

int MST(int n, vector<vector<int>> edges) {
    priority_queue<pair<int, pair<int, int>>,
                   vector<pair<int, pair<int, int>>>,
                   greater<pair<int, pair<int, int>>>> pq;

    for (const auto& edge : edges) {
        int u = edge[0]-1, v = edge[1]-1, weight = edge[2];
        pq.push({weight, {u, v}});
    }

    vector<int> parent(n), size(n, 1);
    for (int i = 0; i < n; i++) parent[i] = i;

    int mstCost = 0;
    int edgesUsed = 0;

    while (!pq.empty() && edgesUsed < n - 1) {
        auto [weight, nodes] = pq.top(); pq.pop();
        int u = nodes.first, v = nodes.second;

        if (findParent(u, parent) != findParent(v, parent)) {
            mstCost += weight;
            unionBySize(u, v, parent, size);
            edgesUsed++;
        }
    }

    return mstCost;
}