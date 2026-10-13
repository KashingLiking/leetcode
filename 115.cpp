#include<iostream>
using namespace std;

// class Solution {
// public:
//     int maxSubarraySumCircular(vector<int>& nums) {
//         int cur = 0,res = nums[0],left = 0,right = 0;
//         for(int i = 0;i<nums.size();i++){
//             cur+=nums[i];
//             res = max(cur,res);            
//             if(cur<0){
//                 cur = 0;
//                 left = i;
//                 right = i;
//             }else{
//                 right++;
//             }
//         }
//         if((right==(nums.size()-1))&&left!=0){
//             int start = 0;
//             while(start<left){
//                 cur+=nums[start];
//                 res = max(cur,res);
//                 start++;
//             }
//         }
//         return res;
//     }
// };这种思路不对

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int curmax = 0,curmin = 0,maxarray = nums[0],minarray = nums[0],sum = 0;
        for(int i = 0;i<nums.size();i++){
            curmax+=nums[i];
            curmin+=nums[i];
            sum+=nums[i];
            maxarray = max(curmax,maxarray);     
            minarray = min(curmin,minarray);       
            if(curmax<0){
                curmax = 0;
            }
            if(curmin>0){
                curmin = 0;
            }
        }
        if(sum-minarray==0){
            return maxarray;
        }
        return max(sum-minarray,maxarray);
    }
};