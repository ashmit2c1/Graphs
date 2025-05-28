#include<bits/stdc++.h>
using namespace std;
// DETECT CYCLE IN AN UNDIRECTED GRAPH USING BFS 
bool checkfunction(int node,vector<bool>&visited,vector<vector<int>>&adj){
    visited[node]=true;
    queue<pair<int,int>>q;
    q.push({node,-1});
    while(q.empty()==false){
        int node=q.front().first;
        int parent=q.front().second;
        q.pop();
        int n=adj[node].size();
        for(int i=0;i<n;i++){
            int neighbor=adj[node][i];
            if(neighbor==parent){
                continue;
            }
            if(visited[neighbor]==true){
                return true;
            }else{
                visited[neighbor]=true;
                q.push({neighbor,node});
            }
        }
    }
    return false;
}
bool check(int n,vector<vector<int>>&adj){
    vector<bool>visited(n,false);
    for(int i=0;i<n;i++){
        if(visited[i]==false){
            if(checkfunction(i,visited,adj)==true){
                return true;
            }
        }
    }
    return false;
}