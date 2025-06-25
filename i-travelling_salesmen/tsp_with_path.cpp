#include<bits/stdc++.h>
using namespace std;
const int MAXN=10;
int dp[1 << MAXN][MAXN];
int parent[1 << MAXN][MAXN];
int tsp(const vector<vector<int>>& distance, int setOfCities, int current, int n) {
    if (setOfCities == (1 << n) - 1) {
        return distance[current][0];
    }
    if (dp[setOfCities][current] != -1) {
        return dp[setOfCities][current];
    }

    int ans = INT_MAX;
    int optimalNextCity = -1; 
    for (int choice = 0; choice < n; choice++) {
        if (!((setOfCities >> choice) & 1)) {
            int newCost = distance[current][choice] + tsp(distance, setOfCities | (1 << choice), choice, n);
            
            if (newCost < ans) {
                ans = newCost;
                optimalNextCity = choice;
            }
        }
    }
    parent[setOfCities][current] = optimalNextCity;
    return dp[setOfCities][current] = ans;
}
vector<int> reconstructPath(int n) {
    vector<int> path;
    int currentCity = 0;
    int currentMask = (1 << 0); 
    path.push_back(0); 
    while (currentMask != (1 << n) - 1) {
        int nextCity = parent[currentMask][currentCity];
        if (nextCity == -1) {
            break;
        }
        path.push_back(nextCity);
        currentCity = nextCity;
        currentMask |= (1 << nextCity); 
    }

    path.push_back(0); 
    return path;
}
int main() {
    vector<vector<int>> dist = {
        {0, 20, 42, 25},
        {20, 0, 30, 34},
        {42, 30, 0, 10},
        {25, 34, 10, 0}
    };

    int n = dist.size();

    // Initialize DP tables with -1
    for (int i = 0; i < (1 << n); ++i) {
        for (int j = 0; j < n; ++j) {
            dp[i][j] = -1;
            parent[i][j] = -1; // Initialize parent table as well
        }
    }

    // Calculate the minimum cost
    // Start with city 0, with only city 0 visited in the mask (1 << 0)
    int minCost = tsp(dist, (1 << 0), 0, n);

    // Reconstruct the path
    vector<int> bestPath = reconstructPath(n);

    // Output the result
    cout << "Minimum Cost: " << minCost << endl;
    cout << "Path: ";
    for (int city : bestPath) {
        cout << city << " ";
    }
    cout << endl;

    return 0;
}