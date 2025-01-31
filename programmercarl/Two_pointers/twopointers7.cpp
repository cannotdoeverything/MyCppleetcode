/*实现 strStr() 函数。

给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

示例 1: 输入: haystack = "hello", needle = "ll" 输出: 2
*/

#include<iostream>
#include<string>
#include<vector>

using namespace std;

void getNext(vector<int>&next, const string&s){
    int j =-1;
    next[0] = j;
    for(int i=1;i<s.size();i++){
        // 如果前后缀不匹配，回退到前一个可能的匹配位置
        while(j>=0 && s[i] != s[j+1]){
            j = next[j];
        }
        if(s[i] == s[j+1]){
            j++;
        }
        next[i]=j;
    }
}
int main(){
    string haystack;
    cin>>haystack;
    string needle;
    cin>>needle;
    if(needle.size() == 0) return 0;
    vector<int>next(needle.size(),-1);
    getNext(next,needle);
    int j = -1;
    for(int i=0; i<haystack.size();i++){
        while(j>=0 && haystack[i] != needle[j+1]){
            j = next[j];
        }
        if(haystack[i] == needle[j+1]){
            j++;
        }
        if(j == (needle.size()-1)) return (i-needle.size()+1);
    }
    return -1;

    //example: heyatsck = aaabaabb, needle = aabaab
    //example: heyatsck = "babba", needle = "bbb" j>=0


    /*int len1 = h                                                                                                                                                                                                                                                                                                                                                                                                                                                                           aystack.size();
    int len2 = needle.size();
    for(int i=0; i<len1; i++){
        string str = haystack.substr(i,len2);
        if(str == needle){
            return i;
            break;
        }
    }
    return -1;*/
}