#include<bits/stdc++.h>
using namespace std;
// RETURN THE NUMBER OF CLOSED ISLANDS, A CLOSED ISLAND IS AN ISLAND THAT IS SURROUNDED BY WATER ON ALL 4 SIDES ( 0 IS LAND 1 IS WATER )
int rows[4]={0,0,-1,1};
int cols[4]={-1,1,0,0};
bool isValid(int i,int j,int r,int c){
    if(i>=0 && j>=0 && i<r && j<c){
        return true;
    }
    return false;
}
void change(int i,int j,vector<vector<int>>&grid){
    grid[i][j]=1;
    queue<pair<int,int>>q;
    q.push({i,j});
    while(q.empty()==false){
        int x=q.front().first;
        int y=q.front().second;
        for(int k=0;k<4;k++){
            int newX = x+rows[k];
            int newY = y+cols[k];
            if(isValid(newX,newY,grid.size(),grid[0].size())==true && grid[newX][newY]==0){
                grid[newX][newY]=1;
                q.push({newX,newY});
            }
        }
    }
}
int closedIslands(vector<vector<int>>&grid){
    int r=grid.size();
    int c=grid[0].size();
    for(int i=0;i<r;i++){
        if(grid[i][0]==0){
            change(i,0,grid);
        }
        if(grid[i][c-1]==0){
            change(i,c-1,grid);
        }
    }
    for(int i=0;i<c;i++){
        if(grid[0][i]==0){
            change(0,i,grid);
        }
        if(grid[r-1][i]==0){
            change(r-1,i,grid);
        }
    }
    int cnt=0;
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[i].size();j++){
            if(grid[i][j]==0){
                change(i,j,grid);
                cnt++;
            }
        }
    }
    return cnt;
}