#include<iostream>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<long long>>map(m,vector<long long>(n,0));
        for(int i = m - 1;i >= 0;i--){
            for(int j = n - 1;j >= 0;j--){
                if(obstacleGrid[i][j]==1){
                    map[i][j] = 0;
                    continue;
                }
                if(i==m-1&&j==n-1){
                    map[i][j] = 1;
                }else if(i==m-1){
                    if(obstacleGrid[i][j+1]==0){
                        map[i][j] = map[i][j+1];
                    }else{
                        map[i][j] = 0;
                    }
                }else if(j==n-1){
                    if(obstacleGrid[i+1][j]==0){
                        map[i][j] = map[i+1][j];
                    }else{
                        map[i][j] = 0;
                    }
                }else{
                    if(obstacleGrid[i+1][j]==0&&obstacleGrid[i][j+1]==0){
                        map[i][j] = map[i+1][j] + map[i][j+1];
                    }else if(obstacleGrid[i+1][j]==0){
                        map[i][j] = map[i+1][j];
                    }else{
                        map[i][j] = map[i][j+1];
                    }
                }
            }
        }
        return map[0][0];
    }
};