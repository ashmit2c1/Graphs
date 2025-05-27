#include<bits/stdc++.h>
using namespace std;
//BREADTH FIRST SEARCH TO FIND THE SHORTEST PATH FROM THE SOURCE NODE 
vector<int>shortestPath(int n,vector<vector<int>>&adj,int src,vector<int>&parent){
    vector<int>distance(n,INT_MAX);
    vector<bool>visited(n,false);
    queue<int>q;
    q.push(src);
    distance[src]=0;
    visited[src]=true;
    while(q.empty()==false){
        int node=q.front();
        q.pop();
        int sz=adj[node].size();
        for(int i = 0; i<sz ; i++){
            int neighbor=adj[node][i];
            if(visited[neighbor]==false){
                visited[neighbor]=true;
                distance[neighbor]=distance[node]+1;
                parent[neighbor]=node;
                q.push(neighbor);
            }
        }
    }
    for(int i = 0; i<n ; i++){
        if(distance[i]==INT_MAX){
            distance[i]=-1;
        }
    }
    return distance;
}
// TRACKING BACK THE PATH FROM THE SOURCE NODE
vector<int>reconstructPath(int destination,vector<int>&parent){
    vector<int>path;
    while(destination!=-1){
        path.push_back(destination);
        destination=parent[destination];
    }
    reverse(path.begin(),path.end());
    return path;
}


