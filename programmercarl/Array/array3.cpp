/*给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
public:
    vector<int> Sortedsquare(vector<int>& nums){
       
        int left = 0, right = nums.size()-1;
        vector<int> res(nums.size(),0);
        int k = res.size()-1;
        while(left<=right){
            if(nums[left]*nums[left]<nums[right]*nums[right]){
                res[k--]=nums[right]*nums[right];
                right--;
            }else{
                res[k--]=nums[left]*nums[left];
                left++;
            }
        }
        return res;
    }
};
int main(){
    Solution sol;
    vector<int> nums = {-4,-1,0,1,9};
    vector<int> res = sol.Sortedsquare(nums);
    for(int i =0;i<res.size();i++)
        cout<<res[i]<<" ";

    cout<<endl;
   
}