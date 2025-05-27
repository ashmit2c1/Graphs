#include <bits/stdc++.h>
using namespace std;
// TICKET ITINERARY
void helperfunction(string node,vector<string>&ans,unordered_map<string,multiset<string>>&adj){
    while(adj[node].empty()==false){
        auto it = adj[node].begin();
        string next = *it; 
        adj[node].erase(it);  
        helperfunction(next, ans, adj);
    }
    ans.push_back(node);
}
vector<string> findItinerary(vector<vector<string>>& tickets) {
    vector<string>ans;
    unordered_map<string,multiset<string>>adj;
    for(int i=0;i<(int)tickets.size();i++){
        string from = tickets[i][0];
        string to = tickets[i][1];
        adj[from].insert(to);
    }
    helperfunction("JFK",ans,adj);
    reverse(ans.begin(),ans.end());
    return ans;
}