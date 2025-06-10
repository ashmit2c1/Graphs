#include<bits/stdc++.h>
using namespace std;

//  YOU ARE GIVEN A NETWORK, YOU CAN TAKE EDGES FROM THE NETWORK AND CONNECTED THE ENTIRE , FIND HOW MANY EDGES YOU NEED 
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
int makeConnected(int n,vector<vector<int>>connections){
    if(connections.size()<n-1){
        return -1;
    }
    vector<int>parent(n);
    for(int i=0;i<n;i++){
        parent[i]=i;
    }
    vector<int>setsize(n,1);
    for(int i=0;i<connections.size();i++){
        int u = connections[i][0]-1;
        int v = connections[i][1]-1;
        unionfunction(u,v,parent,setsize);
    }
    int count=0;
    for(int i=0;i<n;i++){
        int p = findparent(i,parent);
        if(p==i){
            count++;
        }
    }
    return count-1;
}