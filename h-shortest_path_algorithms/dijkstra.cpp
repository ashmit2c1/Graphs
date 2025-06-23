#include<bits/stdc++.h>
using namespace std;

// DIJKSTRA ALGORITHM 
vector<int>dijkstra(int V,vector<vector<pair<int,int>>>&adj){
    vector<int>distance(V,INT_MAX);
    distance[0]=0;
    vector<bool>visited(V,false);
    for(int i=0;i<V;i++){
        int node=-1;
        int value = INT_MAX;
        for(int j=0;j<V;j++){
            if(visited[j]==false && distance[j]<value){
                node=j;
                value = distance[j];
            }
        }
        if(node==-1){
            break;
        }
        int n = adj[node].size();
        visited[node]=true;
        for(int j = 0; j<n ; j++){
            int neighbor=adj[node][j].first;
            int weight = adj[node][j].second;
            if(distance[neighbor] > weight + distance[node]){
                distance[neighbor] = weight + distance[node];
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