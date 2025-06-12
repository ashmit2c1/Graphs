#include <bits/stdc++.h>
using namespace std;

int findParent(int node, vector<int>& parent) {
    if (parent[node] == node) return node;
    return parent[node] = findParent(parent[node], parent);
}

bool unionBySize(int u, int v, vector<int>& parent, vector<int>& size) {
    int parentU = findParent(u, parent);
    int parentV = findParent(v, parent);

    if (parentU == parentV) return false;

    if (size[parentU] < size[parentV]) {
        parent[parentU] = parentV;
        size[parentV] += size[parentU];
    } else {
        parent[parentV] = parentU;
        size[parentU] += size[parentV];
    }
    return true;
}

int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
    vector<int> parentAlice(n + 1), sizeAlice(n + 1, 1);
    vector<int> parentBob(n + 1), sizeBob(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        parentAlice[i] = i;
        parentBob[i] = i;
    }

    int removable = 0, usedAlice = 0, usedBob = 0;

    for (auto& edge : edges) {
        if (edge[0] == 3) {
            bool usedA = unionBySize(edge[1], edge[2], parentAlice, sizeAlice);
            bool usedB = unionBySize(edge[1], edge[2], parentBob, sizeBob);
            if (usedA) usedAlice++;
            if (usedB) usedBob++;
            if (!usedA && !usedB) removable++;
        }
    }

    for (auto& edge : edges) {
        if (edge[0] == 1) {
            if (unionBySize(edge[1], edge[2], parentAlice, sizeAlice)) usedAlice++;
            else removable++;
        } else if (edge[0] == 2) {
            if (unionBySize(edge[1], edge[2], parentBob, sizeBob)) usedBob++;
            else removable++;
        }
    }

    if (usedAlice != n - 1 || usedBob != n - 1) return -1;
    return removable;
}
