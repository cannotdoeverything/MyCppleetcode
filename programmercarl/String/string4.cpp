/*给定一个字符串，逐个翻转字符串中的每个单词。
单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。
返回 单词 顺序颠倒且 单词 之间用单个空格连接的结果字符串。
示例 1：
输入: "the sky is blue"
输出: "blue is sky the"
*/

//可以使用split库函数，分隔单词，然后定义一个新的string字符串，最后再把单词倒序相加
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<sstream>

using namespace std;
class Solution{
private:
    string trim(const string&str){
        int start = 0, end = str.size()-1;
        while(start <= end && isspace(str[start])){
            start++;
        }
        while(end>=start && isspace(str[end])){
            end--;
        }
        return str.substr(start,end-start+1);
    }
    vector<string> split(const string&str){  
    istringstream stream(str);      //从字符串中逐个读取数据的过程
    string word;
    vector<string>words;
    while(stream >> word){  
        /*stream >> word：从 stream（istringstream 对象）中读取下一个以空白字符为分隔符的子串（即单词）并存入变量 word 中。
*/
        words.push_back(word); //最终存储的是字符串中的所有单词，长度等于提取的单词数。
    }
    return words;
}
    string join(const vector<string>&words, const string& delimiter){
    string res;
    for(int i=0;i<words.size();i++){
        res += words[i];
        if(i<words.size()-1){
            res += delimiter;
        }
    }
    return res; 

}
public: 
    string reverseWord(string s){
        s = trim(s);
        vector<string> wordList = split(s);

        // 反转单词列表
        reverse(wordList.begin(), wordList.end());

        // 拼接单词列表为结果字符串
        return join(wordList, " ");

    }
};