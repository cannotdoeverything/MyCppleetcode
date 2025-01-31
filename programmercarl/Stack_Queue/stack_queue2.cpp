/*请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（push、top、pop 和 empty）。

实现 MyStack 类：
void push(int x) 将元素 x 压入栈顶。
int pop() 移除并返回栈顶元素。
int top() 返回栈顶元素。
boolean empty() 如果栈是空的，返回 true ；否则，返回 false*/
#include<iostream>
#include<queue>

using namespace std;

class MyStack{
public:
    queue<int>queue1;
    queue<int>queue2;

MyStack(){

    }

void push(int x){
    queue1.push(x);
}

int pop(){
    int size1 = queue1.size();
    size1--;
    while(size1--){
        queue2.push(queue1.front());
        queue1.pop();
    }
    int res = queue1.front();
    queue1.pop();
    queue1 = queue2;
    while(!queue2.empty()){
        queue2.pop();
    }
    return res;
}

int top(){
    int size1 = queue1.size();
    size1--;
    while (size1--)
    {
        queue2.push(queue1.front());
        queue1.pop();
    }
    int res = queue1.front();   // 留下的最后一个元素就是要回返的值
    queue2.push(queue1.front()); // 获取值后将最后一个元素也加入que2中，保持原本的结构不变
    queue1.pop();
    queue1 = queue2;
    while(!queue2.empty()){
        queue2.pop();
    }
    return res;
}

bool empty(){
    return queue1.empty();
}
};
