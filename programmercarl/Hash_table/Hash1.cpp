/*给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
示例 1: 输入: s = "anagram", t = "nagaram" 输出: true
示例 2: 输入: s = "rat", t = "car" 输出: false
说明: 你可以假设字符串只包含小写字母*/

#include<iostream>
#include<unordered_map>

using namespace std;

class Solution{
public:
    bool isAnagram(string s, string t){
    //方法1
       /* sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        if(s == t) return true;
        else return false; */
    
    //方法2
   /* unordered_map<char,int>record;
    if(s.size() != t.size()) return false;
    for(int i =0; i<s.size();i++){
        ++record[s[i]];
        --record[t[i]];
    }
    for(auto it = record.begin();it!=record.end();it++){
        if(it->second !=0) return false;
    }return false; */

    //方法3
    int record[26] = {0};
    for(int i=0; i<s.size();i++){
        record[s[i]-'a']--;
    }
    for(int i=0; i<t.size();i++){
        record[t[i]-'a']--;
    }
    for (int i = 0; i < 26; i++)
    {
        if(record[i] !=0) return false;
    }
    return true;
    
    }

};
int main(){
    Solution sol;
    string s = "rat";
    string t = "car";
    
    bool res = sol.isAnagram(s,t);
    cout<<(res ? "true" : "false")<<endl;
    return 0;
}