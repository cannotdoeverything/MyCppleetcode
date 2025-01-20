/*题意：给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？找出所有满足条件且不重复的四元组*/

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target){
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        if(nums.size()<4) return {};
        for(int i=0;i<nums.size()-3;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j= i+1;j<nums.size()-2;j++){
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                int left = j+1, right = nums.size()-1;
                while(left<right){
                    long long sum = nums[i]+nums[j]+nums[left]+nums[right]; //防止溢出使用 long long 存储四数之和的结果，避免因为数值过大导致溢出错误。
                    if(sum==target){
                        res.push_back(vector<int>{nums[i],nums[j],nums[left],nums[right]});
                        while(left<right&&nums[left]==nums[left+1]) left++;
                        while(left<right&&nums[right]==nums[right-1]) right--;
                        left++;
                        right--;
                    }else if(sum<target){
                        left++;
                    }else{
                        right--;
                    }
                }
            }
        }
        return res;

    }
};
void printResult(const vector<vector<int>> &res){
    for(const auto& vec : res){
        for(int num : vec){
            cout<<num<<" ";
        }
        cout<<endl;
    }
}
int main(){
    Solution sol;
    vector<int>nums = {1,2,0,-1,-2,0};
    int target = 0;
    vector<vector<int>>res = sol.fourSum(nums,target);
    for(int i = 0; i < res.size(); i++)
    {
        for(int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}