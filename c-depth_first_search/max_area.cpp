#include<bits/stdc++.h>
using namespace std;
int rows[4]={-1,1,0,0}; // for direction in the x axis
int cols[4]={0,0,-1,1}; // for direction in the y axis
bool isValid(int i,int j,int r,int c){
    if(i>=0 && i<r && j>=0 && j<c){
        return true;
    } 
    return false;
}
int helperfunction(int x,int y,vector<vector<int>>&grid){
    int area=1;
    grid[x][y]=0;
    for(int i=0;i<4;i++){
        int newX=x+rows[i];
        int newY=y+cols[i];
        if(isValid(newX,newY,grid.size(),grid[0].size())==true && grid[newX][newY]==1){
            area+=helperfunction(newX,newY,grid);
        }
    }
    return area;
}
int maxAreaOfIsland(vector<vector<int>>grid){
    int r=grid.size();
    int c=grid[0].size();
    int maxArea=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(grid[i][j]==1){
                maxArea=max(maxArea,helperfunction(i,j,grid));
            }
        }
    }
    return maxArea;
}