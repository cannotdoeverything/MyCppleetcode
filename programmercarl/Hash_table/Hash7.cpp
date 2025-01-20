/*给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。

注意： 答案中不可以包含重复的三元组*/
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>res;
        sort(nums.begin(),nums.end());
        for(int i =0;i<nums.size()-1;i++){
            if(nums[i]>0) break;
            if(i>0 && nums[i] == nums[i-1]) continue;
            int left = i+1;
            int right = nums.size()-1;
            while(left<right){
                int sum = nums[i]+ nums[left]+nums[right];
                if(sum==0){
                    res.push_back(vector<int>{nums[i],nums[left],nums[right]});
                    while(left<right && nums[left]== nums[left+1]) left++;
                    while(left<right && nums[right]==nums[right-1]) right--;//去重核心操作，right还是一个数一个数的减下去的，所以在哪里减的都是一样的
                    left++;
                    right--;
                }
                else if(sum<0){
                    left++;
                }else{
                    right--;
                }
            }
        }
        return res;
        
    }
};
/*两数之和就不能使用双指针法，因为两数之和 (opens new window)要求返回的是索引下标， 而双指针法一定要排序，一旦排序之后原数组的索引就被改变了。*/