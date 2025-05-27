#include<bits/stdc++.h>
using namespace std;
// MAXIMAL NETWORK RANK 
int maximalNetworkRank(int n,vector<vector<int>>&roads){
    vector<vector<bool>>connected(n,vector<bool>(n,false));
    vector<int>degree(n,0);
    for(int i=0;i<roads.size();i++){
        int source = roads[i][0];
        int destination = roads[i][1];
        degree[source]++;
        degree[destination]++;
        connected[source][destination]=true;
        connected[destination][source]=true;
    }
    int maxRank = INT_MIN;
    for(int i=0;i<degree.size();i++){
        for(int j=i+1;i<degree.size();j++){
            int rank = degree[j]+degree[i];
            if(connected[i][j]==true){
                rank--;
            }
            maxRank=max(maxRank,rank);
        }
    }
    return maxRank;
}
int main(){
    int n;
    int m;
    cin >> n >> m;
    vector<vector<int>>roads(m);
    for(int i=0;i<m;i++){
        int u;int v;
        cin >> u >> v;
        roads.push_back({u,v});
        roads.push_back({v,u});
    }
    int ans=maximalNetworkRank(n,roads);
    cout << ans << "\n";
}