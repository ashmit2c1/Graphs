#include<bits/stdc++.h>
using namespace std;



int findparent(int node,vector<int>&parent){
    if(parent[node]==node){
        return node;
    }else{
        int leader = findparent(parent[node],parent);
        parent[node]=leader;
        return leader;
    }
}
void unionfunction(int u,int v,vector<int>&parent,vector<int>&setsize){
    int uparent = findparent(u,parent);
    int vparent = findparent(v,parent);

    if(uparent!=vparent){
        if(setsize[uparent]<setsize[vparent]){
            parent[uparent]=vparent;
            setsize[vparent]+=setsize[uparent];
        }else{
            parent[vparent]=uparent;
            setsize[uparent]+=setsize[vparent];
        }
    }
}
void implementDSU(int n,vector<pair<int,int>>&connections){
    vector<int>parent(n);
    vector<int>setsize(n,1);
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
    for(int i=0;i<(int)connections.size();i++){
        int u = connections[i].first;
        int v = connections[i].second;
        unionfunction(u,v,parent,setsize);
    }

}