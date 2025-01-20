/*给定一个字符串 s 和一个整数 k，从字符串开头算起, 每计数至 2k 个字符，就反转这 2k 个字符中的前 k 个字符。
如果剩余字符少于 k 个，则将剩余字符全部反转。
如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。*/

#include<iostream>
#include<string>

using namespace std;

class Solution {
private:
    void reverse(string &s,int k,int left, int right){
        while(left<right){
            swap(s[left],s[right]);
            left++;
            right--;
        }
    }
public:
    string reverseStr(string s, int k) {
        int len = s.size();
        int i =0;
        while(i<s.size()){
            if(len>=2*k){
                reverse(s,k,i,i+k-1);
                len = len-2*k;
                i = i+2*k;
            }else if(len >= k && len< 2*k){
                reverse(s,k,i,i+k-1);
                i= i+len;
            }else if(len<k){
                reverse(s,k,i,i+len-1);
                i = i+len;
            }
        }
        return s;

        for(int i =0; i<s.size();i += 2*k){
            if(i+k<=s.size()){
                reverse(s,k,i,i+k-1);
                continue;
            }
            reverse(s,k,i,s.size()-1);
        }
    }
};
int main(){
    string s = "abcdefg";
    int k = 2;
    Solution sol;
    string res = sol.reverseStr(s,k);
    for(int i =0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
}