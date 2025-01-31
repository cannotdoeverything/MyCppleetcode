/*给定一个非空的字符串，判断它是否可以由它的一个子串重复多次构成。给定的字符串只含有小写英文字母，并且长度不超过10000。
示例 1:
输入: "abab"
输出: True
解释: 可由子字符串 "ab" 重复两次构成。
*/

#include<iostream>
#include<string>

using namespace std;
int main(){
    string s;
    cin>>s;
    int n = s.size();
    for(int len=1; len<= n/2 ; len++){
        if(n%len == 0){
            bool isRepeated = true;
            for(int i = len; i<n;i++){
                if(s[i] != s[i%len]){
                   isRepeated = false;
                   break; 
                }
            }
            if(isRepeated){
               cout<<"true"<<endl; 
               return 0; 
            } 
        }
          
    }
    cout<<"false"<<endl;
    return 0;

    string doubled = s+s;
    string str = doubled.substr(1,doubled.size()-2);
    if(str.find(s) != string::npos){
        return true;
    }else{
        return false;
    }
}