#include<bits/stdc++.h>
using namespace std;
int findparent(int u,vector<int>&parent){
    if(parent[u]==u){
        return u;
    }else{
        int leader = findparent(parent[u],parent);
        parent[u]=leader;
        return leader;
    }
}
void unionfunction(int u,int v,vector<int>&parent,vector<int>&setsize){
    int parent_u = findparent(u,parent);
    int parent_v = findparent(v,parent);
    
    if(parent_u!=parent_v){
        if(setsize[parent_u]<setsize[parent_v]){
            parent[parent_u]=parent_v;
            setsize[parent_v]+=setsize[parent_u];
        }else{
            parent[parent_v]=parent_u;
            setsize[parent_u]+=setsize[parent_v];
        }
    }
}
vector<int> findUselessConnection(vector<vector<int>> edges) {
        int n = edges.size();
        vector<int>parent(n);
        vector<int>setsize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
            setsize[i]=1;
        }
        for(int i=0;i<(int)edges.size();i++){
            int u = edges[i][0]-1;
            int v = edges[i][1]-1;
            int parent_u = findparent(u,parent);
            int parent_v = findparent(v,parent);
            if(parent_u==parent_v){
                return {u,v};
            }
            unionfunction(u,v,parent,setsize);
        }
        return {};
        
}