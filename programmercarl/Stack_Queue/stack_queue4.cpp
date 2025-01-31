/*给出由小写字母组成的字符串 S，重复项删除操作会选择两个相邻且相同的字母，并删除它们。

在 S 上反复执行重复项删除操作，直到无法继续删除。

在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。*/

#include<iostream>
#include<stack>

using namespace std;

int main(){
    stack<char>st;
    string s;
    cin>>s;
    for(int i=0; i<s.size();i++){
        if(!st.empty() && s[i]==st.top()){
            st.pop();
        }else{
          st.push(s[i]);  
        }
    }
    string result = "";
        while (!st.empty()) {
            result += st.top();  // 注意栈中字符的顺序
            st.pop();
        }
        reverse(result.begin(), result.end()); // 反转字符串，恢复原来的顺序
        cout<<result<<endl;
}

