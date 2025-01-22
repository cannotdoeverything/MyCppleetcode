/*实现 strStr() 函数。

给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

示例 1: 输入: haystack = "hello", needle = "ll" 输出: 2

示例 2: 输入: haystack = "aaaaa", needle = "bba" 输出: -1*/

#include<iostream>
#include<string>

using namespace std;

//KMP算法，考虑前缀后缀长度
class Solution{
private: 
    void getNext(int *next, string &s){
        int j =-1;
        next[0] = j;
        for(int i=1; i<s.size();i++){
            while(j>0 && s[i] != s[j+1]){
                j = next[j];
            }
            if(s[i]==s[j+1]) j++;
            next[i] = j;
        }
    }
public:
    int strStr(string haystacks, string needle){
        if(needle.size() == 0) return 0;
        vector<int> next(needle.size(),0);
        getNext(&next[0],needle);
        int j =-1;
        for(int i =0;i<haystacks.size();i++){
            while(j>0 && haystacks[i] != needle[j+1]){ //注意边界
                j = next[j];
            }
            if(haystacks[i] == needle[j+1]){
                j++;
            }
            if(j == (needle.size()-1)){
                return (i-needle.size()+1);
            }
        }
        return -1;
    }
};