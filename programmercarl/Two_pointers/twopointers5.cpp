/*给定一个字符串，逐个翻转字符串中的每个单词。

示例 1：
输入: "the sky is blue"
输出: "blue is sky the"
*/

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

void reverseStr(string &s, int left,int right){
        while(left<right){
        swap(s[left],s[right]);
        left++;
        right--;
    }
}

int main(){
    string s;
    getline(cin,s);     //读取整行
    int slow = 0;
    for(int i=0; i<s.size();i++){
        if(s[i] != ' '){
            if(slow > 0 && s[slow - 1] != ' ') s[slow++] = ' ';
            while(i<s.size() && s[i] != ' '){
                s[slow++] = s[i++];
            }
        }
    }
    s.resize(slow);
    reverse(s.begin(),s.end());
    int j = 0;
    for(int i=0; i<=s.size(); i++){
        if(s[i] == ' ' || i == s.size()){
            reverseStr(s,j,i-1);
            j= i+1;
        }
    }
    cout<<s<<endl;
    return 0;
}