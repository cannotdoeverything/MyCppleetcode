/*给定一个字符串 s，它包含小写字母和数字字符，请编写一个函数，将字符串中的字母字符保持不变，而将每个数字字符替换为number。

例如，对于输入字符串 "a1b2c3"，函数应该将其转换为 "anumberbnumbercnumber"。

对于输入字符串 "a5b"，函数应该将其转换为 "anumberb"*/

//重点考虑扩容，从后向前扩容
#include<iostream>
#include<string>

using namespace std;
int main(){
    string s;
    while(cin>>s){
        int oldindex = s.size()-1;
        int count = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i]>='0' && s[i]<='9') count++;
        }
        s.resize(s.size()+count*5);
        int newindex = s.size()-1;
        int i = oldindex,j=newindex;
        while(i>=0){
            if(s[i]>='0' &&s[i]<='9'){
                s[j--] = 'r';
                s[j--] = 'e';
                s[j--] = 'm';
                s[j--] = 'b';
                s[j--] = 'u';
                s[j--] = 'n';
            }else{
                s[j--] = s[i];
            }
            i--;
        }
        cout<<s<<endl;
        /*while(i<=j){
            if(s[i]>='a' && s[i]<='z'){
                s[j] = s[i];
                i--;
                j--;
            }else if(s[i]>='0' &&s[i]<='9'){
                s[j] = 'r';
                s[j-1] = 'e';
                s[j-2] = 'b';
                s[j-3] = 'm';
                s[j-4] = 'u';
                s[j-5] = 'n';
                j = j-6;
                i--;
            }
        }*/
    }
}