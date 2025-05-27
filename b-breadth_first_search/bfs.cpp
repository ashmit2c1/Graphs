#include<bits/stdc++.h>
using namespace std;
// BREADTH FIRST SEARCH STANDARD CODE 
vector<int>bfsTraversal(int n,vector<vector<int>>&adj){
    queue<int>q;
    vector<bool>visited(n,false);
    q.push(0);
    vector<int>ans;
    while(q.empty()){
        int node=q.front();
        q.pop();
        ans.push_back(node);
        int n=adj[node].size();
        for(int i = 0; i<n ; i++){
            int neighbor=adj[node][i];
            if(visited[neighbor]==false){
                visited[neighbor]=true;
                q.push(neighbor);
            }
        }
    }
    return ans;
}
