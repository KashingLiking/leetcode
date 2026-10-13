#include<iostream>
using namespace std;

class Solution {
public:
    vector<vector<bool>>mp;
    bool exist(vector<vector<char>>& board, string word) {
        mp.clear();
        mp.resize(board.size(), vector<bool>(board[0].size(), false));
        for(int i = 0;i<board.size();i++){
            for(int j = 0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    string copy = word;
                    copy.erase(0,1);
                    if(dfs(i,j,copy,board)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool dfs(int col,int row,string word,vector<vector<char>>& board){
        if(word.size()==0){
            return true;
        }
        mp[col][row]=true;
        bool col1 = false,col2 = false,row1= false,row2 = false;
        string copy = word;
        copy.erase(0);
        if(col-1>=0){
            if((!mp[col-1][row])&&board[col-1][row]==word[0]){
                col1 = dfs(col-1,row,copy,board);
            }
        }
        if(col+1<board.size()){
            if((!mp[col+1][row])&&board[col+1][row]==word[0]){
                col2 = dfs(col+1,row,copy,board);
            }
        }
        if(row-1>=0){
            if((!mp[col][row-1])&&board[col][row-1]==word[0]){
                row1 = dfs(col,row-1,copy,board);
            }
        }
        if(row+1<board[0].size()){
            if((!mp[col][row+1])&&board[col][row+1]==word[0]){
                row2 = dfs(col,row+1,copy,board);
            }
        }
        mp[col][row] = false;
        return col1||col2||row1||row2;
    }
};