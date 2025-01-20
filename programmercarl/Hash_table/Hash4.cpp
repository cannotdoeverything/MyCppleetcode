/*给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。*/

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution{
public:
    vector<int> twoSum(vector<int>& nums, int target){
        unordered_map<int,int>map;
        for(int i =0;i<nums.size();i++){
            auto iter =  map.find(target-nums[i]);
            if(iter != map.end()){
                return{iter->second,i};
            }
            map.insert(pair<int,int>(nums[i],i));    
        }
        return {};

        unordered_map<int,int>map;
        for(int i =0;i<nums.size();i++){
            int n =  target-nums[i];
            if(map.find(n) != map.end()){
                return {map.find(n)->second,i};
            }
            map.insert(pair<int,int>(nums[i],i));   
        }
        return {};

    }
};