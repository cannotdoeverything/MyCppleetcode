/*给定一个数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。

返回滑动窗口中的最大值。

进阶：
你能在线性时间复杂度内解决此题吗？*/

/*动态扩展：deque 可以动态扩展，不需要像数组一样预先分配固定大小。
高效操作：
在头部和尾部插入、删除元素的时间复杂度为O(1)。
在中间插入、删除元素的时间复杂度为 O(n)。
单调队列保证队列里单调递减或递增的原则，所以叫做单调队列*/

#include<iostream>
#include<list>
#include<deque>
#include<vector>

using namespace std;

class MyQueue{
public:
    deque<int>que;
    void pop(int value){
        if(!que.empty() && value == que.front()){       //保持单调队列里单调递减，此时队列出口元素就是窗口里最大元素。


            que.pop_front();   //头部删除
        }
    }
    void push(int value){
        while (!que.empty() && value>que.back())
        {
            que.pop_back();
        }
        que.push_back(value);
        
    }
    int front(){
        return que.front();
    }
};

int main(){
    MyQueue que;
    vector<int>nums;
    int i;
    while(cin>>i){
        nums.push_back(i);
        if(cin.get()=='\n') break;
    }
    int k;
    cin>>k;
    vector<int>result;
    for(int i=0; i<k;i++){
        que.push(nums[i]);
    }
    result.push_back(que.front());
    for(int i=k; i<nums.size();i++){
        que.pop(nums[i-k]);
        que.push(nums[i]);
        result.push_back(que.front());
    }
    for(int i=0; i<result.size();i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}
