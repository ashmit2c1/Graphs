#include<bits/stdc++.h>
using namespace std;

// TRAVELLING SALES MAN PROBLEM USING BITMASKING 
int tsp(vector<vector<int>>& distance, int setOfCities, int current, int n) {
    if (setOfCities == (1 << n) - 1) {
        return distance[current][0];
    }
    int ans = INT_MAX;
    for (int choice = 0; choice < n; choice++) {
        if ((setOfCities & (1 << choice)) == 0) {  // Corrected this line
            int newCost = distance[current][choice] + tsp(distance, setOfCities | (1 << choice), choice, n);
            ans = min(ans, newCost);
        }
    }
    return ans;
}

int main() {
    vector<vector<int>> dist = {
        {0, 20, 42, 25},
        {20, 0, 30, 34},
        {42, 30, 0, 10},
        {25, 34, 10, 0}
    };
    cout << tsp(dist, 1, 0, 4) << "\n";  // Start with city 0 and set the mask for city 0 as visited (1)
    return 0;
}
