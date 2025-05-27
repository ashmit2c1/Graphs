#include<bits/stdc++.h>
using namespace std;
// SNAKES AND LADDERS SOLUTION 1 
int min_dice_throws(int n,vector<pair<int,int>>snakes,vector<pair<int,int>>ladders){
    int board_size=n*n+1;
    vector<int>board(board_size,-1);
    vector<bool>visited(board_size,false);
    queue<pair<int,int>>q;
    q.push({1,0});
    visited[1]=true;
    while(q.empty()==false){
        int current = q.front().first;
        int throws = q.front().second;
        q.pop();
        if(current==board_size-1){
            return throws;
        }
        for(int i=1;i<=6;i++){
            int next = current + i;
            if(next>board_size){
                continue;
            }
            if(board[next]!=-1){
                next=board[next];
            }
            if(visited[next]==false){
                visited[next]=true;
                q.push({next,throws+1});
            }
        }
    }
    return -1;
}
// SNAKES AND LADDERS SOLUTION 2 
bool isValid(int position,int n,vector<bool>&visited){
    if(position<=n*n && visited[position]==false){
        return true;
    }else{
        return false;
    }
}
int min_dice_throws(int n,vector<pair<int,int>>snakes,vector<pair<int,int>>ladders){
    int boardsize=n+1;
    vector<int>board(boardsize,-1);
    vector<bool>visited(boardsize,false);
    queue<int>q;
    q.push(1);
    visited[1]=true;
    for(int i=0;i<snakes.size();i++){
        int start = snakes[i].first;
        int end = snakes[i].second;
        board[start]=end;
    }
    for(int i=0;i<ladders.size();i++){
        int start = ladders[i].first;
        int end = ladders[i].second;
        board[start]=end;
    }
    int moves=0;
    while(q.empty()==false){
        int s = q.size();
        for(int i=0;i<s;i++){
            int current = q.front();
            q.pop();
            if(current==boardsize-1){
                return moves;
            }
            for(int dice = 1;dice<=6;dice++){
                int next = current+dice;
                if(isValid(next,n,visited)==true){
                    visited[next]=true;
                    if(board[next]!=-1){
                        next=board[next];
                    }
                    q.push(next);
                }
            }
        }
        moves++;
    }
    return -1;
}