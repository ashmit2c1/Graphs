#include<bits/stdc++.h>
using namespace std;
// KEYS AND ROOMS
void helperfunction(int node,int &count,vector<bool>&visited,vector<vector<int>>&rooms){
    visited[node]=true;
    count++;
    int n=rooms[node].size();
    for(int i=0;i<n;i++){
        int neighbor=rooms[node][i];
        if(visited[neighbor]==false){
            helperfunction(neighbor,count,visited,rooms);
        }
    }
}
bool canVisitAllRooms(vector<vector<int>>&rooms){
    int n=rooms.size();
    int count=0;
    vector<bool>visited(n,false);
    helperfunction(0,count,visited,rooms);
    if(count==n){
        return true;
    }
    return false;
}
int main(){
    
}