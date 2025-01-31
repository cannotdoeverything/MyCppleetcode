/*给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。

不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并原地修改输入数组。

元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。*/

/*双指针法（快慢指针法）： 通过一个快指针和慢指针在一个for循环下完成两个for循环的工作。

定义快慢指针

快指针：寻找新数组的元素 ，新数组就是不含有目标元素的数组
慢指针：指向更新 新数组下标的位置
*/

#include<vector>
#include<iostream>

using namespace std;

int main(){
    vector<int>nums;
    int n;
    while(1){
        cin>>n;
        nums.push_back(n);
        if(cin.get()=='\n') break;
    }
    int val;
    cin>>val;
    int cur = 0;
    for(int i = 0;i<nums.size(); i++){
        if(nums[i] != val){
            nums[cur++] = nums[i]; 
        }
    }
    cout<<cur<<endl;
    return 0;
}