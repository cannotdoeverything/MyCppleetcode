/*题意：给定两个数组，编写一个函数来计算它们的交集
说明： 输出结果中的每个元素一定是唯一的。 我们可以不考虑输出结果的顺序。*/

#include<iostream>
#include<unordered_set>
#include<vector>
#include<utility>

using namespace std;
class Solution{
public:
    vector<int>intersection(vector<int>&nums1, vector<int>&nums2){
        unordered_set<int> res;
        unordered_set<int>record(nums1.begin(),nums1.end()); //会去重
        
        for(int i=0; i<nums2.size();i++){
            if(record.find(nums2[i]) != record.end()){
                res.insert(nums2[i]);
            }
        }
        
        return vector<int>(res.begin(),res.end());
        
    }
};



