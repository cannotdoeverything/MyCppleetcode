/*
给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。
*/


#include<iostream>
#include<vector>
#include<cassert>
using namespace std;

class Solution{
public:
    int search(vector<int>& nums, int target){
    int left = 0,right = nums.size();
    while(left<right){
        int mid = left+(right-left)/2;
        if(nums[mid]<target){
            left = mid+1;
        }else if(nums[mid]>target){
            right = mid;
        }else{
            return mid;
        }
    }
    return -1;
    }
};

int main() {
    Solution sol;

    // 示例用例
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target = 9;

    int result = sol.search(nums, target);

    // 打印结果
    if (result != -1) {
        cout << "找到目标值 " << target << " 的索引为: " << result << endl;
    } else {
        cout << "目标值 " << target << " 不存在于数组中" << endl;
    }

    return 0;
}
