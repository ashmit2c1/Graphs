#include<bits/stdc++.h>
using namespace std;
bool check(int node,int parent,vector<bool>&visited,vector<vector<int>>&adj){
    visited[node]=true;
    int n=adj[node].size();
    for(int i=0;i<n;i++){
        int neighbor=adj[node][i];
        if(neighbor==parent){
            continue;
        }
        if(visited[neighbor]==true){
            return true;
        }else{
            if(check(neighbor,node,visited,adj)==true){
                return true;
            }
        }
    }
    return false;
}
bool solve(int n,vector<vector<int>>&adj){
    vector<bool>visited(n,false);
    for(int i=0;i<n;i++){
        if(visited[i]==false){
            if(check(i,-1,visited,adj)==true){
                return true;
            }
        }
    }
    return false;
}