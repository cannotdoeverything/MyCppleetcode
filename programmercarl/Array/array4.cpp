/*给定一个含有 n 个正整数的数组和一个正整数 s ，
找出该数组中满足其和 ≥ s 的长度最小的 连续 子数组，并返回其长度。如果不存在符合条件的子数组，返回 0。*/

#include<iostream>
#include<vector>

using namespace std;
class Solution{
public:
    int minSubarrary(vector<int>&nums,int target){
        int left=0,sum = 0;
        int minlen = INT_MAX;
        
        for(int right = 0; right<nums.size(); right++){
            sum += nums[right];
            while(sum >= target){
                minlen = min(minlen,right-left+1);
                sum -=nums[left];
                left++;
            }
        }
       return minlen == INT_MAX ? 0 : minlen;
    }
};
int main(){
    Solution sol;
    int target = 7;
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int res = sol.minSubarrary(nums,target);
    cout<<res<<endl;
    return 0;
}