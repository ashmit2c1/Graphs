#include<bits/stdc++.h>
using namespace std;

// FIND THE ISLAND WITH THE MAX AREA
bool isValid(int i,int j,int r,int c){
    if(i>=0 && j>=0 && i<r && j<c){
        return true;
    }
    return false;
}
int rows[4]={-1,1,0,0};
int cols[4]={0,0,-1,1};
int calc(int i,int j,vector<vector<int>>&grid){
    grid[i][j]=0;
    int area=1;
    queue<pair<int,int>>q;
    q.push({i,j});
    while(q.empty()==false){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int k=0;k<4;k++){
            int newX = x + rows[k];
            int newY = y + cols[k];
            if(isValid(newX,newY,grid.size(),grid[0].size()) && grid[newX][newY]==1){
                area+=calc(newX,newY,grid);
            }
        }
    }
    return area;
}
int maxAreaOfIsland(vector<vector<int>>&grid){
    int maxArea=INT_MIN;
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[i].size();j++){
            if(grid[i][j]==1){
                maxArea=max(maxArea,calc(i,j,grid));
            }
        }
    }
    return maxArea;
}