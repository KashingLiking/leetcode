#include<iostream>
using namespace std;
//这道题我只能想到先用二分法找到一个等于target的数组下标，然后朝左右扩展，但是好像这个方法万一数组中的值全等于target的话就不是logn了
//满足logn的话把左右下标分开找就行

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0){
            vector<int>tp{-1,-1};
            return tp;
        }
        int left = 0, right = nums.size(), leftsig = 0, rightsig = 0, mid = 0;
        while(left<right){
            mid = (left + right)/2;
            if(nums[mid]<target){
                left = mid + 1;
            }else{
                right = mid;
            }
        }
        leftsig = left;
        if(nums[leftsig]!=target){
            vector<int>tp{-1,-1};
            return tp;
        }
        left = 0,right = nums.size();
        while(left<right){
            mid = (left + right)/2;
            if(nums[mid]<=target){
                left = mid + 1;
            }else{
                 right = mid;
            }
        }
        rightsig = left-1;
        vector<int>res;
        res.push_back(leftsig);
        res.push_back(rightsig);
        return res;
    }
};