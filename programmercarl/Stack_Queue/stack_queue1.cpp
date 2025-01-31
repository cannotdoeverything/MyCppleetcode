/*使用栈实现队列的下列操作：

push(x) -- 将一个元素放入队列的尾部。
pop() -- 从队列首部移除元素。
peek() -- 返回队列首部的元素。
empty() -- 返回队列是否为空。
你只能使用标准的栈操作 -- 也就是只有 push to top, peek/pop from top, size, 和 is empty 操作是合法的。
你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。
假设所有操作都是有效的 （例如，一个空的队列不会调用 pop 或者 peek 操作）。
*/

#include <iostream>
#include <stack>

using namespace std;

//成员变量和函数封装在 class MyQueue 中
class MyQueue {
public:
    stack<int> stIn;  // 存储新元素的栈
    stack<int> stOut; // 用于模拟队列先进先出的栈

    MyQueue() {}

    // 入队操作
    void push(int x) {
        stIn.push(x);
    }

    // 出队操作
    int pop() {
        if (stOut.empty()) {

        /*  stIn.empty()	判断栈是否为空，空返回 true，非空返回 false。
            stIn.empty() == 1	表示栈为空。
            stIn.empty() == 0	表示栈非空。
            */
            while (!stIn.empty()) {
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
        int res = stOut.top();
        stOut.pop();
        return res;
    }

    // 获取队首元素
    int peek() {
        if (stOut.empty()) {
            while (!stIn.empty()) {
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
        return stOut.top();
    }

    // 判断队列是否为空
    bool empty() {
        return stIn.empty() && stOut.empty();
    }
};

int main() {
    MyQueue q;

    q.push(1);
    q.push(2);
    cout << "队首元素: " << q.peek() << endl;  // 输出 1
    cout << "出队元素: " << q.pop() << endl;    // 输出 1
    cout << "队列是否为空: " << q.empty() << endl; // 输出 0 (false)

    q.push(3);
    cout << "出队元素: " << q.pop() << endl;    // 输出 2
    cout << "出队元素: " << q.pop() << endl;    // 输出 3
    cout << "队列是否为空: " << q.empty() << endl; // 输出 1 (true)

    return 0;
}