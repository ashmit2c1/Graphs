#include<bits/stdc++.h>
using namespace std;
// CHEAPEST FLIGHT WITHIN K STOPS 
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<vector<pair<int,int>>>adj(n);
    for(int i=0;i<flights.size();i++){
        int source = flights[i][0];
        int destination = flights[i][1];
        int price = flights[i][2];
        adj[source].push_back({destination,price});
    }
    queue<pair<int,pair<int,int>>>q; // source, currentcost, stops
    q.push({src,{0,0}});
    int minCost = INT_MAX;
    while(q.empty()==false){
        int currentCity = q.front().first;
        int currentCost = q.front().second.first;
        int currentStops = q.front().second.second;
        q.pop();
        if(currentCity==dst){
            minCost=min(minCost,currentCost);
        }
        if(currentStops<=k){
            int n=adj[currentCity].size();
            for(int i = 0; i<n ; i++){
                int neighbor = adj[currentCity][i].first;
                int cost = currentCost+adj[currentCity][i].second;
                q.push({neighbor,{cost,currentStops+1}});
            }
        }
    }
    if(minCost==INT_MAX){
        return -1;
    }else{
        return minCost;
    }
}
// CHEAPEST FLIGHT WITH K STOPS USING VECTOR TO STORE THE RESULTS 
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<vector<pair<int,int>>>adj(n);
    for(int i=0;i<flights.size();i++){
        int source = flights[i][0];
        int destination = flights[i][1];
        int price = flights[i][2];
        adj[source].push_back({destination,price});
    }
    queue<pair<int,pair<int,int>>>q; // source, currentcost, stops
    q.push({src,{0,0}});
    int minCost = INT_MAX;
    vector<vector<int>>visited(n,vector<int>(k+1,INT_MAX));
    while(q.empty()==false){
        int currentCity = q.front().first;
        int currentCost = q.front().second.first;
        int currentStops = q.front().second.second;
        q.pop();
        if(currentCity==dst){
            minCost=min(minCost,currentCost);
        }
        if(currentStops<=k){
            int n=adj[currentCity].size();
            for(int i = 0; i<n ; i++){
                int neighbor = adj[currentCity][i].first;
                int cost = currentCost+adj[currentCity][i].second;
                if(visited[neighbor][currentStops+1]>cost){
                    visited[neighbor][currentStops+1]=cost;
                    q.push({neighbor,{currentCost,currentStops+1}});
                }
            }
        }
    }
    if(minCost==INT_MAX){
        return -1;
    }else{
        return minCost;
    }
}
// CHEAPEST FLIGHT WITHIN K STOPS 
int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
vector<vector<pair<int,int>>>adj(n);
    for(auto it:flights){
        adj[it[0]].push_back({it[1],it[2]});
    }
    vector<int>distance(n,1e9);
    distance[src]=0;
    queue<pair<int,pair<int,int>>>q;
    q.push({0,{src,0}});
    while(!q.empty()){
        int stop=q.front().first;
        int node=q.front().second.first;
        int cost=q.front().second.second;
        q.pop();
        for(auto it:adj[node]){
            int adjnode=it.first;
            int wt=it.second;
            if(cost+wt<distance[adjnode] && stop<=k){
                distance[adjnode]=cost+wt;
                q.push({stop+1,{adjnode,cost+wt}});
            }
        }
    }
    if(distance[dst]==1e9) return -1;
    return distance[dst];

}