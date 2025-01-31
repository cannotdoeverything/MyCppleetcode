/*给定一个字符串 s 和一个整数 k，从字符串开头算起, 每计数至 2k 个字符，就反转这 2k 个字符中的前 k 个字符。

如果剩余字符少于 k 个，则将剩余字符全部反转。

如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。
*/

#include<iostream>
#include<string>

using namespace std;


void reverseStr(string &s,int left, int right){
    while(left<right){
        swap(s[left],s[right]);
        left++;
        right--;
    }
}

int main(){
    string s;
    cin>>s;
    int k;
    cin>>k;
    for(int i=0; i<s.size(); i += 2*k){
        if(i+k<=s.size()){
            reverseStr(s,i,i+k-1);
            continue;
        }
        reverseStr(s,i,s.size()-1);
    }
    cout<<s<<endl;
    return 0;
}

