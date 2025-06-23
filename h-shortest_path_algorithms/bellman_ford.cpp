#include<bits/stdc++.h>
using namespace std;
// BELLMAN FORD ALGORITHMS 

vector<int>bellmanford(int V,vector<vector<int>>&edges,int SRC){
    vector<int>distance(V,INT_MAX);
    distance[SRC]=0;
    for(int i=0;i<V-1;i++){
        for(int j=0;j<edges.size();j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int weight = edges[j][2];
            if(distance[u]!=INT_MAX && distance[v]>weight+distance[u]){
                distance[v]=weight+distance[u];
            }
        }
    }
    for(int i=0;i<edges.size();i++){
        int u =edges[i][0];
        int v= edges[i][1];
        int weight = edges[i][2];
        if(distance[u]!=INT_MAX && weight+ distance[u]<distance[v]){
            return {-1};
        }
    }
    for(int i=0;i<distance.size();i++){
        if(distance[i]==INT_MAX){
            distance[i]=-1;
        }
    }
    return distance;
}