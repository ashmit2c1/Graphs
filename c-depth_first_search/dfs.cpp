#include<bits/stdc++.h>
using namespace std;
// DEPTH FIRST SEARCH CODE 
void dfsFunction(int node,vector<bool>&visited,vector<int>&ans,vector<vector<int>>&adj){
    visited[node]=true;
    ans.push_back(node);
    int n=adj[node].size();
    for(int i = 0; i<n ; i++){
        int neighbor=adj[node][i];
        if(visited[neighbor]==false){
            dfsFunction(neighbor,visited,ans,adj);
        }
    }
}
vector<int>dfsTraversal(int V,vector<vector<int>>&adj){
    vector<int>ans;
    vector<bool>visited(V,false);
    for(int i=0;i<V;i++){
        if(visited[i]==false){
            dfsFunction(i,visited,ans,adj);
        }
    }
    return ans;
}