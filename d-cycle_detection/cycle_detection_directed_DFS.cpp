#include<bits/stdc++.h>
using namespace std;
bool check(int node,vector<bool>&path,vector<bool>&visited,vector<vector<int>>&adj){
    visited[node]=true;
    path[node]=true;
    int n=adj[node].size();
    for(int i=0;i<n;i++){
        int neighbor=adj[node][i];
        if(path[neighbor]==true){
            return true;
        }
        if(visited[neighbor]==false){
            if(check(neighbor,visited,path,adj)==true){
                return true;
            }
        }
    }
    path[node]=false;
    return true;
}
bool solve(int n,vector<vector<int>>&adj){
    vector<bool>visited(n,false);
    vector<bool>path(n,false);
    for(int i=0;i<n;i++){
        if(visited[i]==false){
            if(check(i,path,visited,adj)==true){
                return true;
            }
        }
    }
    return false;
}