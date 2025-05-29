#include<bits/stdc++.h>
using namespace std;

// TOPOLOGICAL SORT USING DFS
void toposortfunction(int node,vector<bool>&visited,vector<vector<int>>&adj,stack<int>&st){
    visited[node]=true;
    int n=adj[node].size();
    for(int i=0;i<n;i++){
        int neighbor=adj[node][i];
        if(visited[neighbor]==false){
            toposortfunction(neighbor,visited,adj,st);
        }
    }
    st.push(node);

}
vector<int>topologicalSort(int n,vector<vector<int>>adj){
    vector<bool>visited(n,false);
    stack<int>st;
    for(int i=0;i<n;i++){
        if(visited[i]==false){
            toposortfunction(i,visited,adj,st);
        }
    }
    vector<int>ans;
    while(st.empty()==false){
        int node=st.top();
        st.pop();
        ans.push_back(node);
    }
    return ans;
}