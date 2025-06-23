#include<bits/stdc++.h>
using namespace std;

// FIND THE SHORTEST DISTANCE TO ALL NODES FROM A SOURCE NODE 
vector<int>findDistance(int V,vector<vector<int>>&adj){
    vector<int>distance(V,INT_MAX);
    vector<bool>visited(V,false);
    queue<int>q;
    q.push(0);
    visited[0]=true;
    distance[0]=0;
    while(q.empty()==false){
        int node=q.front();
        q.pop();
        int n=adj[node].size();
        for(int i = 0; i<n ; i++){
            int neighbor = adj[node][i];
            if(visited[neighbor]==false){
                visited[neighbor]=true;
                distance[neighbor]=1+distance[node];
                q.push(neighbor);
            }
        }
    }
    for(int i=0;i<distance.size();i++){
        if(distance[i]==INT_MAX){
            distance[i]=-1;
        }
    }
    return distance;
}