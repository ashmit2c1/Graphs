#include<bits/stdc++.h>
using namespace std;

int buildRoads(vector<vector<int>>&Coordinates){
    vector<vector<pair<int,int>>>adj(Coordinates.size());
    int n=Coordinates.size();
    for(int i = 0; i<n ; i++){
        int originalX = Coordinates[i][0];
        int originalY = Coordinates[i][1];
        vector<pair<int,int>>temp;
        for(int j = 0; j<n ; j++){
            int destinationX = Coordinates[j][0];
            int destinationY = Coordinates[j][1];
            int weight = min(abs(destinationX-originalX),abs(destinationY-originalY));
            temp.push_back({j,weight});
        }
        adj[i]=temp;
    }
    vector<int>isMST(n,false);
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    vector<int>parent(n,-1);
    pq.push({0,{0,-1}});
    int cost=0;
    while(pq.empty()==false){
        int weight = pq.top().first;
        int node = pq.top().second.first;
        int par = pq.top().second.second;
        pq.pop();
        if(isMST[node]==false){
            isMST[node]=true;
            cost+=weight;
            parent[node]=par;
            int m=adj[node].size();
            for(int i = 0; i<m ; i++){
                int neighbor = adj[node][i].first;
                int weight = adj[node][i].second;
                pq.push({weight,{neighbor,node}});
            }
        }
    }
    return cost;
}

int main(){
    int n; cin >> n;
    vector<vector<int>> adj(n, vector<int>(2)); 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 2; j++){
            cin >> adj[i][j];
        }
    }
    int ans = buildRoads(adj);
    cout << ans << "\n";
}