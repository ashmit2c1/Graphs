#include<bits/stdc++.h>
using namespace std;

bool isValid(int i, int j, int r, int c) {
    return i >= 0 && i < r && j >= 0 && j < c;
}
int shortest_path(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<int>> distance(n, vector<int>(m, INT_MAX));
    distance[0][0] = grid[0][0];

    int rows[4] = {-1, 1, 0, 0};
    int cols[4] = {0, 0, -1, 1};

    int tot = n * m;
    for (int i = 0; i < tot; i++) {
        int minDist = INT_MAX;
        int x = -1, y = -1;

        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (!visited[j][k] && distance[j][k] < minDist) {
                    x = j;
                    y = k;
                    minDist = distance[j][k];
                }
            }
        }

        if (x == -1) break;

        visited[x][y] = true;

        for (int d = 0; d < 4; d++) {
            int newX = x + rows[d];
            int newY = y + cols[d];

            if (isValid(newX, newY, n, m)) {
                if (distance[newX][newY] > distance[x][y] + grid[newX][newY]) {
                    distance[newX][newY] = distance[x][y] + grid[newX][newY];
                }
            }
        }
    }

    return distance[n - 1][m - 1];
}