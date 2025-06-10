#include <bits/stdc++.h>
using namespace std;

int n=100000;
int findparent(int u, vector<int>& parent) {
    if (parent[u] == u) {
        return u;
    } else {
        int leader_element = findparent(parent[u], parent);
        parent[u] = leader_element;
        return leader_element;
    }
}

void unionSet(int u, int v, vector<int>& parent, vector<int>& setsize) {
    int parent_u = findparent(u, parent);
    int parent_v = findparent(v, parent);
    if (parent_u != parent_v) {
        if (setsize[parent_u] < setsize[parent_v]) {
            parent[parent_u] = parent_v;
            setsize[parent_v] += setsize[parent_u];
        } else {
            parent[parent_v] = parent_u;
            setsize[parent_u] += setsize[parent_v];
        }
    }
}
bool isForest(int n, vector<vector<int>>& edges) {
    vector<int> parent(n), setsize(n, 1);
    iota(parent.begin(), parent.end(), 0);

    for (auto& edge : edges) {
        int u = edge[0], v = edge[1];
        if (u == v) return false; // self-loop -> cycle

        int pu = findparent(u, parent);
        int pv = findparent(v, parent);

        if (pu == pv) return false; // cycle detected

        unionSet(u, v, parent, setsize);
    }
    return true;
}
