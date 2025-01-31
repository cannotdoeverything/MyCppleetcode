/*给定一个非空的字符串，判断它是否可以由它的一个子串重复多次构成。给定的字符串只含有小写英文字母，并且长度不超过10000*/

#include<iostream>
#include<string>

using namespace std;

int main(){
    string s;
    cin>>s;
    int res = 0;
    string doubled = s+s;
        string str = doubled.substr(1,doubled.size()-2);
        if(str.find(s) != string::npos){
            res = 1;
        }
        cout<<(res ? "true" : "false")<<endl;

}