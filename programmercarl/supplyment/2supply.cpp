/*给定一个int数组，将正数移动到数组左边，负数移动到数组右边*/

#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    void leftrightsort(vector<int> &nums){
        int left = 0, right = nums.size()-1;
        while(left<right){
            if(nums[left]<0 && nums[right]>=0)
            swap(nums[left],nums[right]);
        if(nums[left]>=0){
            left++;
        }
        if(nums[right]<0){
            right--;
        }
        }
    }
};
int main(){
    Solution sol;
    vector<int>nums = {8, 6, 4, -3, 5, -2, -1, 0, 1, -9, 1, -1};

    cout << "Original: ";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    sol.leftrightsort(nums);

    cout << "Sorted: ";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
    
    return 0;
}