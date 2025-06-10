#include<bits/stdc++.h>
using namespace std;

// CHECK IF TWO ELEMENTS ARE CONNECTED OR NOT 
int findparent(int node,vector<int>&parent){
    if(parent[node]==node){
        return node;
    }else{
        int  leader = findparent(parent[node],parent);
        parent[node]=leader;
        return leader;
    }
}
void unionfunction(int u,int v,vector<int>&setsize,vector<int>&parent){
    int parentU = findparent(u,parent);
    int parentV = findparent(v,parent);
    if(parentU!=parentV){
        if(setsize[parentU]<setsize[parentV]){
            parent[parentU]=parentV;
            setsize[parentV]+=setsize[parentU];
        }else{
            parent[parentV]=parentU;
            setsize[parentU]+=setsize[parentV];
        }
    }else{
        return;
    }
}
vector<bool>check(int n,vector<pair<int,int>>queries,vector<pair<int,int>>&connections){
    vector<int>parent(n);
    vector<int>setsize(n,0);
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
    vector<bool>ans;
    for(int i=0;i<connections.size();i++){
        int u = connections[i].first;
        int v = connections[i].second;
        unionfunction(u,v,parent,setsize);
    }
    for(int i=0;i<queries.size();i++){
        int u = queries[i].first;
        int v = queries[i].second;
        if(findparent(u,parent)!=findparent(v,parent)){
            ans.push_back(false);
        }else{
            ans.push_back(true);
        }
    }
    return ans;
}