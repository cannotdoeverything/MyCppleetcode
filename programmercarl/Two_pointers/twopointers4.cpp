/*给定一个字符串 s，它包含小写字母和数字字符，请编写一个函数，将字符串中的字母字符保持不变，而将每个数字字符替换为number。

例如，对于输入字符串 "a1b2c3"，函数应该将其转换为 "anumberbnumbercnumber"。

对于输入字符串 "a5b"，函数应该将其转换为 "anumberb"

输入：一个字符串 s,s 仅包含小写字母和数字字符。

输出：打印一个新的字符串，其中每个数字字符都被替换为了number

*/
#include<iostream>
#include<string>

using namespace std;

int main(){
    string s;
    cin>>s;
    int len =s.size();
    int count =0;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0' && s[i]<='9'){
            count++;
        }
    }
    s.resize((len+5*count),'\0');
    int right = s.size()-1;
    for(int j=len-1;j>=0;j--){
        if(s[j]>='a' && s[j]<='z'){
            s[right]=s[j];
            right--;
        }else if(s[j]>='0' && s[j]<='9'){
            s[right--] = 'r';
            s[right--] = 'e';
            s[right--] = 'b';
            s[right--] = 'm';
            s[right--] = 'u';
            s[right--] = 'n';
        }
    }
    cout<<s<<endl;
    return 0;
}


