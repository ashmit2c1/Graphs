#include<bits/stdc++.h>
using namespace std;
// FIND THE LARGEST NETWORK SIZE IN A GROUP OF NETWORKS 
int findparent(int element,vector<int>&parent){
    if(parent[element]==element){
        return element;
    }else{
        return findparent(parent[element],parent);
    }
}
void unionfunction(int u,int v,vector<int>&parent,vector<int>&setsize){
    int parentu=findparent(u,parent);
    int parentv=findparent(v,parent);
    if(parentu!=parentv){
        if(setsize[parentv]<setsize[parentu]){
            swap(parentu,parentv);
        }
        parent[parentv]=parentu;
        setsize[parentu]+=setsize[parentv];
    }
}
int solvefunction(vector<int>&parent,vector<int>&setsize,vector<pair<int,int>>&connections){
    for(int i=0;i<connections.size();i++){
        int u=connections[i].first;
        int v=connections[i].second;
        unionfunction(u,v,parent,setsize);
    }
    int maxindex=-1;
    int maxsetsize=INT_MIN;
    for(int i=0;i<setsize.size();i++){
        int sz=setsize[i];
        if(sz>maxsetsize){
            maxindex=i;
            maxsetsize=max(maxsetsize,sz);
        }
    }
    return maxsetsize;
}