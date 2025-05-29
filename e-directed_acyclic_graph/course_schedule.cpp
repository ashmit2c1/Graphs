#include<bits/stdc++.h>
using namespace std;
vector<int>courseSchedule(int numCourses,vector<vector<int>>&preRequisties){
    vector<vector<int>>adj(numCourses);
    for(int i=0;i<(int)preRequisties.size();i++){
        int a=preRequisties[i][0];
        int b=preRequisties[i][1];
        adj[a].push_back(b);
    }
    vector<int>indegree(numCourses,0);
    for(int i=0;i<(int)adj.size();i++){
        int sz=adj[i].size();
        for(int j=0;j<sz;j++){
            int node=adj[i][j];
            indegree[node]++;
        }
    }
    queue<int>q;
    for(int i=0;i<(int)indegree.size();i++){
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
        for(int i = 0; i<n ; i++){
            int neighbor=adj[node].size();
            indegree[neighbor]--;
            if(indegree[neighbor]==0){
                q.push(neighbor);
            }
        }
    }
    if(ans.size()!=numCourses){
        return {};
    }else{
        return ans;
    }
}