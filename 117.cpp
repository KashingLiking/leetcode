#include<iostream>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0){
            return false;
        }
        int top = 0,bottom = matrix.size()-1,row = 0;
        while(top<=bottom){
            row = (top+bottom)/2;
            if(matrix[row][0]>target){
                bottom = row-1;
            }else if(matrix[row][0]<=target&&matrix[row][matrix[0].size()-1]>=target){
                break;
            }else{
                top = row+1;
            }
        }
        int left = 0, right = matrix[0].size()-1,col = 0;
        while(left<=right){
            col = (left+right)/2;
            if(matrix[row][col]==target){
                return true;
            }else if(matrix[row][col]<target){
                left = col+1;
            }else{
                right = col-1;
            }
        }
        return false;
    }
};