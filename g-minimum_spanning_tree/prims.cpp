#include<bits/stdc++.h>
using namespace std;
// PRIM'S ALGORITHM FOR MINIMUM SPANNING TREE 
int spanningTree(int V,vector<vector<int>>adj[]){
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
    vector<bool>isMST(V,false);
    vector<int>parent(V);
    int totalCost=0;
    pq.push({0,{0,-1}});
    while(pq.empty()==false){
        int weight = pq.top().first;
        int node = pq.top().second.first;
        int par = pq.top().second.second;
        pq.pop();
        if(isMST[node]==false){
            isMST[node]=true;
            parent[node]=par;
            int n=adj[node].size();
            totalCost+=weight;
            for(int i = 0; i<n ; i++){
                int neighbor=adj[node][i][0];
                int weight = adj[node][i][1];
                pq.push({weight,{neighbor,node}});
            }
        }
    }
    return totalCost;
}