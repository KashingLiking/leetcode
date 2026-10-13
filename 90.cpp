#include<iostream>
using namespace std;

class Solution {
public:
    vector<vector<char>>map;
    void solve(vector<vector<char>>& board) {
        map = board;
        for(int i = 0;i<map.size();i++){
            if(map[i][0]=='O'){
                link(i,0);
            }
            if(map[i][map[0].size()-1]=='O'){
                link(i,map[0].size()-1);
            }
        }
        for(int i = 0;i<map[0].size();i++){
            if(map[0][i]=='O'){
                link(0,i);
            }
            if(map[map.size()-1][i]=='O'){
                link(map.size()-1,i);
            }
        }
        for(int i = 0;i<map.size();i++){
            for(int j = 0;j<map[0].size();j++){
                if(map[i][j]=='O'){
                    board[i][j] = 'X';
                }else if(map[i][j]=='#'){
                    board[i][j]=='O';
                }else{
                    board[i][j] = 'X';
                }
            }
        }
    }
    void link(int col,int row){
        map[col][row] = '#';
        if(col-1>=0&&map[col-1][row]=='O'){
            link(col-1,row);
        }
        if(col+1<map.size()&&map[col+1][row]=='O'){
            link(col+1,row);
        }
        if(row-1>=0&&map[col][row-1]=='O'){
            link(col,row-1);
        }
        if(row+1<map[0].size()&&map[col][row+1]=='O'){
            link(col,row+1);
        }
    }
};