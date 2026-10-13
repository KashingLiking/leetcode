#include<iostream>
using namespace std;

class Solution {
public:
    vector<vector<char>>map;
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        map = grid;
        for(int i = 0;i<map.size();i++){
            for(int j = 0;j<map[0].size();j++){
                if(map[i][j]=='1'){
                    res++;
                    link(i,j);
                }
            }
        }
        return res;
    }
    void link(int col,int row){
        map[col][row]='0';
        if(col+1<map.size()&&map[col+1][row]=='1'){
            link(col+1,row);
        }
        if(col-1>=0&&map[col-1][row]=='1'){
            link(col-1,row);
        }
        if(row+1<map[0].size()&&map[col][row+1]=='1'){
            link(col,row+1);
        }
        if(row-1>=0&&map[col][row-1]=='1'){
            link(col,row-1);
        }
    }
};