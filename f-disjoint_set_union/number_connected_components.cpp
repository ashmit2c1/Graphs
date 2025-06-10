#include<bits/stdc++.h>
using namespace std;
// NUMBER OF CONNECTED COMPONENTS using DFS
void dfsFunction(int node,vector<bool>&visited,vector<vector<int>>&adj){
    visited[node]=true;
    int n=adj[node].size();
    for(int i=0;i<n;i++){
        int neighbor=adj[node][i];
        if(visited[neighbor]==false){
            dfsFunction(neighbor,visited,adj);
        }
    }
}
int numberOfConnectedComponents(int n,vector<vector<int>>&edges){
    vector<bool>visited(n,false);
    int count=0;
    vector<vector<int>>adj(n);
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0;i<n;i++){
        if(visited[i]==false){
            dfsFunction(i,visited,adj);
            count++;
        }
    }
    return count;
}
// NUMNBER OF COMPONENTS using DSU
int findparent(int node,vector<int>&parent){
    if(parent[node]==node){
        return node;
    }else{
        int  leader = findparent(parent[node],parent);
        parent[node]=leader;
        return leader;
    }
}
void unionfunction(int u,int v,vector<int>&setsize,vector<int>&parent){
    int parentU = findparent(u,parent);
    int parentV = findparent(v,parent);
    if(parentU!=parentV){
        if(setsize[parentU]<setsize[parentV]){
            parent[parentU]=parentV;
            setsize[parentV]+=setsize[parentU];
        }else{
            parent[parentV]=parentU;
            setsize[parentU]+=setsize[parentV];
        }
    }else{
        return;
    }
}
int numberOfConnectedComponents(int n,vector<vector<int>>&edges){
    vector<int>parent(n);
    vector<int>setsize(n);
    for(int i=0;i<n;i++){
        parent[i]=i;
        setsize[i]=0;
    }
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        unionfunction(u,v,setsize,parent);
    }
    int count=0;
    for(int i=0;i<n;i++){
        if(findparent(i,parent)==i){
            count++;
        }
    }
    return count;
}