/*字符串的右旋转操作是把字符串尾部的若干个字符转移到字符串的前面。给定一个字符串 s 和一个正整数 k，请编写一个函数，将字符串中的后面 k 个字符移到字符串的前面，实现字符串的右旋转操作。*/

#include<iostream>
#include<string>

using namespace std;

int main(){
    string s;
    cin>>s;
    int k;
    cin>>k;
    int n = s.size();
    k = k%n;
    s = s.substr(n-k,k)+s.substr(0,n-k);
    cout<<s<<endl;
    return 0;
}