#include<bits/stdc++.h>
using namespace std;
// PASS A MESSAGE FROM 1 TO N, FIND THE SHORTEST DISTANCE IF A PATH EXISTS

int messageRoute(int n,vector<vector<int>>&edges){
    vector<vector<int>>adj(n);
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0]-1;
        int v=edges[i][1]-1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>distance(n,false);
    vector<bool>visited(n,false);
    queue<int>q;
    q.push(0);
    visited[0]=true;
    distance[0]=true;
    while(q.empty()==false){
        int node=q.front();
        if(node==n-1){
            return distance[node]+1;
        }
        q.pop();
        int sz=adj[node].size();
        for(int i=0;i<sz;i++){
            int neighbor=adj[node][i];
            if(visited[neighbor]==false){
                distance[neighbor]=distance[node]+1;
                visited[neighbor]=true;
                q.push(neighbor);
            }
        }
    }
    return -1;
}