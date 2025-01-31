/*根据 逆波兰表示法，求表达式的值。

有效的运算符包括 + ,  - ,  * ,  / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。

说明：

整数除法只保留整数部分。 给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。*/

#include<iostream>
#include<stack>

using namespace std;

int main(){
    string str;
    vector<string> tokens;
    while(getline(cin,str)){
        if(str.empty()) break;
        tokens.push_back(str);
    } //输入存在问题
    stack<long long>st;
    for(int i=0; i<tokens.size();i++){
       if(tokens[i]=="+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
        long long  num1 = st.top();
        st.pop(); 
       long long num2 = st.top();
       st.pop();
       if(tokens[i] == "+")   st.push(num2 + num1);
       if(tokens[i] == "-")   st.push(num2 - num1);
       if(tokens[i] == "*")   st.push(num2*num1);
       if(tokens[i] == "/")   st.push(num2/num1);
       }else{
        st.push(stoll(tokens[i]));  
        //strtoll() 函数接受字符串、指向字符的指针和整数值 - 基数作为其参数，将字符串的内容解释为给定基数的整数并返回一个 long long int 值。
        //strol() 在函数调用中作为参数提供的字符串转换为long int。将其作为long int值返回
       }
    }
    long long res = st.top();
    cout<<res<<endl;
    return 0;
}