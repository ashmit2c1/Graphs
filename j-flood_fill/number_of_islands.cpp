#include<bits/stdc++.h>
using namespace std;
// CALCULATE THE NUMBER OF ISLANDS IN THE GIVEN GRAP
int rows[4]={-1,1,0,0};
int cols[4]={0,0,-1,1};
bool isValid(int i,int j,int r,int c){
    if(i>=0 && i<r && j>=0 && j<c){
        return true;
    }
    return false;
}
int numIslands(vector<vector<int>>&grid){
    int cnt=0;
    int r=grid.size();
    int c=grid[0].size();
    queue<pair<int,int>>q;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(grid[i][j]==1){
                grid[i][j]=0;
                q.push({i,j});
                cnt++;
                while(q.empty()==false){
                    int x=q.front().first;
                    int y=q.front().second;
                    q.pop();
                    for(int k=0;k<4;k++){
                        int newX=x+rows[k];
                        int newY=y+cols[k];
                        if(isValid(newX,newY,r,c) && grid[newX][newY]==1){
                            q.push({newX,newY});
                            grid[newX][newY]=0;
                        }
                    }
                }
            }
        }
    }
    return cnt;
}
// FOLLOW UP ( COLOR THE ISLANDS )
void colorIslands(vector<vector<int>>&grid){
    int cnt=0;
    int r=grid.size();
    int c=grid[0].size();
    queue<pair<int,int>>q;
    int color=2;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(grid[i][j]==1){
                grid[i][j]=color;
                q.push({i,j});
                cnt++;
                while(q.empty()==false){
                    int x=q.front().first;
                    int y=q.front().second;
                    q.pop();
                    for(int k=0;k<4;k++){
                        int newX=x+rows[k];
                        int newY=y+cols[k];
                        if(isValid(newX,newY,r,c) && grid[newX][newY]==1){
                            q.push({newX,newY});
                            grid[newX][newY]=color;
                        }
                    }
                }
                color++; // here extra color is counted once there are no islands left 
            }
        }
    }
    color--;
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[i].size();j++){
            if(grid[i][j]==color){
                grid[i][j]=1;
            }
        }
    }
}
int main(){
    int n;cin >> n;
    int m;cin >> m;
    vector<vector<int>>grid(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> grid[i][j];
        }
    }
    vector<vector<int>>copy=grid;
    cout << numIslands(copy) << "\n";
    cout << "\n";
    colorIslands(grid);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
}