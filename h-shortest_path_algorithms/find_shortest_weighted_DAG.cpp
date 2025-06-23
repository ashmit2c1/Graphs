#include<bits/stdc++.h>
using namespace std;
// FIND THE SHORTEST DISTANCE IN DIRECTED ACYCLIC GRAPH WEIGHTED 
void topo(int node,stack<int>&st,vector<bool>&visited,vector<vector<pair<int,int>>>&adj){
    visited[node]=true;
    int n=adj[node].size();
    for(int i = 0; i<n ; i++){
        int neighbor=adj[node][i].first;
        if(visited[neighbor]==false){
            topo(neighbor,st,visited,adj);
        }
    }
    st.push(node);
}
vector<int>findShortest(int V,vector<vector<int>>&edges){
    vector<vector<pair<int,int>>>adj(V);
    for(int i=0;i<edges.size();i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];
        adj[u].push_back({v,weight});
    }
    stack<int>st;
    vector<bool>visited(V,false);
    topo(0,st,visited,adj);
    vector<int>distance(V,INT_MAX);
    distance[0]=0;
    while(st.empty()==false){
        int node=st.top();
        st.pop();
        int n = adj[node].size();
        for(int i = 0; i<n ; i++){
            int neighbor=adj[node][i].first;
            int weight = adj[node][i].second;
            distance[neighbor]=weight+distance[node];
        }
    }
    for(int i=0;i<distance.size();i++){
        if(distance[i]==INT_MAX){
            distance[i]=-1;
        }
    }
    return distance;
}