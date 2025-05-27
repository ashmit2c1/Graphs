#include<bits/stdc++.h>
using namespace std;
// DETERMINE ASTRONAUT PAIRS
void helperfunction(int node,int &num,vector<bool>&visited,vector<vector<int>>&adj){
    visited[node]=true;
    num++;
    int n=adj[node].size();
    for(int i = 0; i<n ; i++){
        int neighbor=adj[node][i];
        if(visited[neighbor]==false){
            helperfunction(neighbor,num,visited,adj);
        }
    }
}
int count_pairs(int n,vector<pair<int,int>>&astronauts){
    vector<vector<int>>adj(n);
    for(int i=0;i<astronauts.size();i++){
        int ast1 = astronauts[i].first;
        int ast2 = astronauts[i].second;
        adj[ast1].push_back(ast2);
        adj[ast2].push_back(ast1);
    }
    vector<int>cnt;
    vector<bool>visited(n,false);
    for(int i = 0; i<n;i++){
        int num=0;
        if(visited[i]==false){
            helperfunction(i,num,visited,adj);
            cnt.push_back(num);
        }
    }
    int totpairs = n*(n-1)/2;
    for(int i=0;i<cnt.size();i++){
        int intra=cnt[i]*(cnt[i]-2)/2;
        totpairs-=intra;
    }
    return totpairs;
}