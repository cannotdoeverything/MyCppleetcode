/*给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。

不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并原地修改输入数组。

元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。*/
#include<iostream>
#include<vector>

using namespace std;
class Solution{
public:
    int removeElement(vector<int>& nums, int val){
        /*int size = nums.size();
        for(int i=0; i<size; i++){
            if(nums[i]==val){
                for(int j=i+1; j<size; j++){
                    nums[j-1]=nums[j];
                }
                size--;
                i--;
            }
        }
        return size;*/

        int cur = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != val){
                nums[cur++] = nums[i];
            }
        }
        return cur;

        /*int left = 0,right = nums.size()-1;
        while(left<=right){
            if(nums[left]==val){
                nums[left] = nums[right];
                right--;
            }else{
                left++;
            }
        }
        return left; 双指针*/
    }
};
int main() {
    Solution sol;

    // 示例用例
    vector<int> nums = {3,2,2,3};
    int val = 3;

    int res = sol.removeElement(nums, val);

    // 打印结果
    cout<<res<<endl;

    return 0;
}