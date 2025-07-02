#include <bits/stdc++.h>
using namespace std;

bool isValid(int i, int j, int r, int c) {
    return i >= 0 && j >= 0 && i < r && j < c;
}

int rows[4] = {-1, 1, 0, 0};
int cols[4] = {0, 0, -1, 1};
void floodFill(vector<vector<int>> &image, int sr, int sc, int newColor) {
    int originalColor = image[sr][sc];
    if (originalColor == newColor) return; 
    image[sr][sc] = newColor;
    queue<pair<int, int>> q;
    q.push({sr, sc});
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int newX = x + rows[i];
            int newY = y + cols[i];
            if (isValid(newX, newY, image.size(), image[0].size()) && image[newX][newY] == originalColor) {
                image[newX][newY] = newColor;
                q.push({newX, newY});
            }
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> image(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> image[i][j];
        }
    }
    int newColor, sr, sc;
    cin >> newColor >> sr >> sc;
    floodFill(image, sr, sc, newColor);
    for (int i = 0; i < image.size(); i++) {
        for (int j = 0; j < image[i].size(); j++) {
            cout << image[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}