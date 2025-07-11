#include<bits/stdc++.h>
using namespace std;

// TRAVELLING SALES MAN PROBLEM USING BITMASKING 
int tsp(vector<vector<int>>& distance, int setOfCities, int current, int n,vector<vector<int>>&dp) {
    if (setOfCities == (1 << n) - 1) {
        return distance[current][0];
    }
    if(dp[setOfCities][current]!=-1){
        return dp[setOfCities][current];
    }
    int ans = INT_MAX;
    for (int choice = 0; choice < n; choice++) {
        if ((setOfCities & (1 << choice)) == 0) {  // Corrected this line
            int newCost = distance[current][choice] + tsp(distance, setOfCities | (1 << choice), choice, n,dp);
            ans = min(ans, newCost);
        }
    }
    dp[setOfCities][current]=ans;
    return ans;
}

int main() {
    int n=4;
    vector<vector<int>> dist = {
        {0, 20, 42, 25},
        {20, 0, 30, 34},
        {42, 30, 0, 10},
        {25, 34, 10, 0}
    };
    vector<vector<int>>dp(1<<n,vector<int>(n,-1));
    cout << tsp(dist, 1, 0, 4,dp) << "\n"; 
    return 0;
}
