/*字符串的右旋转操作是把字符串尾部的若干个字符转移到字符串的前面。给定一个字符串 s 和一个正整数 k，请编写一个函数，将字符串中的后面 k 个字符移到字符串的前面，实现字符串的右旋转操作。

例如，对于输入字符串 "abcdefg" 和整数 2，函数应该将其转换为 "fgabcde"。

输入：输入共包含两行，第一行为一个正整数 k，代表右旋转的位数。第二行为字符串 s，代表需要旋转的字符串。

输出：输出共一行，为进行了右旋转操作后的字符串。*/

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(){
    int k;
    cin>>k;
    string s;
    cin>>s;
    int len = s.size();
    if(k<=0 && k>=len)   k = k%len;
    string res = s.substr(len-k,k) + s.substr(0,len-k);

    reverse(s.begin(),s.end());
    reverse(s.begin(),s.begin()+k); //反转的区间是左开右闭，反转前 k 个字符（[0, k)）
    reverse(s.begin()+k,s.end());

    
    cout<<res<<endl;

    return 0;
}