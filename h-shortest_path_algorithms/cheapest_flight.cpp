#include<bits/stdc++.h>
using namespace std;
// CHEAPEST FLIGHT WITHIN K STOPS 
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
vector<vector<pair<int,int>>>adj(n);
    for(auto it:flights){
        adj[it[0]].push_back({it[1],it[2]});
    }
    vector<int>distance(n,1e9);
    distance[src]=0;
    queue<pair<int,pair<int,int>>>q;
    q.push({0,{src,0}});
    while(!q.empty()){
        int stop=q.front().first;
        int node=q.front().second.first;
        int cost=q.front().second.second;
        q.pop();
        for(auto it:adj[node]){
            int adjnode=it.first;
            int wt=it.second;
            if(cost+wt<distance[adjnode] && stop<=k){
                distance[adjnode]=cost+wt;
                q.push({stop+1,{adjnode,cost+wt}});
            }
        }
    }
    if(distance[dst]==1e9) return -1;
    return distance[dst];
}
// USING DIJKSTRA
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<vector<pair<int, int>>> adj(n);
    for (auto it : flights) {
        adj[it[0]].push_back({it[1], it[2]});
    }

    vector<int> distance(n, 1e9);
    distance[src] = 0;

    // Min-heap: {totalCost, stopsUsed, node}
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    pq.push({0, 0, src});

    while (!pq.empty()) {
        auto [cost, stop, node] = pq.top();
        pq.pop();

        if (stop > k) continue;

        for (auto it : adj[node]) {
            int adjnode = it.first;
            int wt = it.second;

            if (cost + wt < distance[adjnode] && stop <= k) {
                distance[adjnode] = cost + wt;
                pq.push({cost + wt, stop + 1, adjnode});
            }
        }
    }

    if (distance[dst] == 1e9) return -1;
    return distance[dst];
}

// USING BELLMAN FORD ALGORITHM
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<int> prev(n, 1e9);
    prev[src] = 0;

    for (int i = 0; i <= k; i++) {
        vector<int> curr = prev;
        for (auto& flight : flights) {
            int u = flight[0];
            int v = flight[1];
            int wt = flight[2];

            if (prev[u] != 1e9 && prev[u] + wt < curr[v]) {
                curr[v] = prev[u] + wt;
            }
        }
        prev = curr;
    }

    return prev[dst] == 1e9 ? -1 : prev[dst];
}
