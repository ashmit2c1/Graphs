#include<bits/stdc++.h>
using namespace std;

void helper(int node,int target,vector<int>&path,int&ans,vector<bool>&visited,vector<vector<int>>&adj){
    visited[node]=true;
    path.push_back(node);
    if(node==target){
        ans++;
    }
    int n=adj[node].size();
    for(int i = 0; i<n ; i++){
        int neighbor=adj[node][i];
        if(visited[neighbor]==false){
            helper(neighbor,target,path,ans,visited,adj);
        }
    }
    path.pop_back();
    visited[node]=false;
}
int solve(int n,vector<pair<int,int>>&edges){
    vector<vector<int>>adj(n);
    for(int i=0;i<(int)edges.size();i++){
        int u =edges[i].first-1;
        int v = edges[i].second-1;
        adj[u].push_back(v);
    }
    vector<int>path;
    int ans=0;
    vector<bool>visited(n,false);
    helper(0,n-1,path,ans,visited,adj);
    return ans;
}
int main(){
    int n;
    int m;
    cin >> n >> m;
    vector<pair<int,int>>edges;
    for(int i=0;i<m;i++){
        int u;
        int v;
        cin >> u >> v;
        edges.push_back({u,v});
    }
    int ans=solve(n,edges);
    cout << ans << "\n";
}