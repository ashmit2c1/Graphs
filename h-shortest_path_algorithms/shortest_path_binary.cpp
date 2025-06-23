#include<bits/stdc++.h>
using namespace std;
// APPROACH 1 USING BFS 
int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n = grid.size();
    if (grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1;

    vector<vector<bool>> visited(n, vector<bool>(n, false));
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;

    int steps = 1;
    int dx[] = {-1, -1, -1,  0, 0, 1, 1, 1};
    int dy[] = {-1,  0,  1, -1, 1, -1, 0, 1};

    while (!q.empty()) {
        int sz = q.size();
        while (sz--) {
            auto [x, y] = q.front(); q.pop();
            if (x == n - 1 && y == n - 1) return steps;

            for (int d = 0; d < 8; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx >= 0 && ny >= 0 && nx < n && ny < n &&
                    grid[nx][ny] == 0 && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
        steps++;
    }

    return -1;
}
// APPROACH 2 USING DIJKSTRA
bool isValid(int i, int j, int r, int c) {
    return i >= 0 && i < r && j >= 0 && j < c;
}

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n = grid.size();
    if (grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1;

    vector<vector<bool>> visited(n, vector<bool>(n, false));
    vector<vector<int>> distance(n, vector<int>(n, INT_MAX));
    distance[0][0] = 1;

    int rows[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
    int cols[8] = {0, 0, -1, 1, -1, 1, 1, -1};

    int tot = n * n;
    for (int i = 0; i < tot; i++) {
        int minDist = INT_MAX;
        int x = -1, y = -1;

        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (!visited[j][k] && distance[j][k] < minDist) {
                    x = j;
                    y = k;
                    minDist = distance[j][k];
                }
            }
        }

        if (x == -1) break;
        visited[x][y] = true;

        for (int d = 0; d < 8; d++) {
            int newX = x + rows[d];
            int newY = y + cols[d];

            if (isValid(newX, newY, n, n) && grid[newX][newY] == 0 && !visited[newX][newY]) {
                if (distance[newX][newY] > distance[x][y] + 1) {
                    distance[newX][newY] = distance[x][y] + 1;
                }
            }
        }
    }

    return (distance[n - 1][n - 1] == INT_MAX) ? -1 : distance[n - 1][n - 1];
}
