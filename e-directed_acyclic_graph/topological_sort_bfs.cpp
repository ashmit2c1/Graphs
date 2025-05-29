#include<bits/stdc++.h>
using namespace std;
// TOPOLOGICAL SORT USING BFS ( KAHNS ALGORITHM )
vector<int>kahnsAlgorithms(int n,vector<vector<int>>&adj){
    vector<int>indegree(n,0);
    for(int i=0;i<n;i++){
        int sz=adj[i].size();
        for(int j=0;j<sz;j++){
            int node=adj[i][j];
            indegree[node]++;
        }
    }
    queue<int>q;
    for(int i=0;i<indegree.size();i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    vector<int>ans;
    while(q.empty()==false){
        int node=q.front();
        q.pop();
        ans.push_back(node);
        int n=adj[node].size();
        for(int i=0;i<n;i++){
            int neighbor=adj[node][i];
            indegree[neighbor]--;
            if(indegree[neighbor]==0){
                q.push(neighbor);
            }
        }
    }
    return ans;
}