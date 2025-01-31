/*给定一个非空的整数数组，返回其中出现频率前 k 高的元素。

示例 1:
输入: nums = [1,1,1,2,2,3], k = 2
输出: [1,2]*/

//优先级队列
//堆是一棵完全二叉树，树中每个结点的值都不小于（或不大于）其左右孩子的值.
//如果父亲结点是大于等于左右孩子就是大顶堆，小于等于左右孩子就是小顶堆。

/*大顶堆（堆头是最大元素），小顶堆（堆头是最小元素），如果懒得自己实现的话，
就直接用priority_queue（优先级队列）就可以了，底层实现都是一样的，从小到大排就是小顶堆，从大到小排就是大顶堆。*/
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<unordered_map>
#include<queue>


using namespace std;
class mycomparison {
    public:
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second > rhs.second; //lhs.second > rhs.second 表示按照 pair 的第二个元素（即频率）进行升序排序
        }
    };

int main(){
    vector<int>nums;
    int num;
    while(cin>>num){
        nums.push_back(num);
        if(cin.get() == '\n') break;
    }
    int k;
    cin>>k;
    unordered_map<int,int>frequenctMap;
    for(auto iter : nums){
        frequenctMap[iter]++;
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que;
    /*这里创建了一个最小堆 pri_que，其中存储的元素类型是 pair<int, int>，
    表示元素的值和它的频率。vector<pair<int, int>> 是底层容器，mycomparison 是比较函数
    */


    for (unordered_map<int, int>::iterator it = frequenctMap.begin(); it != frequenctMap.end(); it++) {
            pri_que.push(*it);
            if (pri_que.size() > k) { // 如果堆的大小大于了K，则队列弹出，保证堆的大小一直为k
                pri_que.pop();
            }
        }

        // 找出前K个高频元素，因为小顶堆先弹出的是最小的，所以倒序来输出到数组
        vector<int> result(k);
        for (int i = k - 1; i >= 0; i--) {
            result[i] = pri_que.top().first;
            pri_que.pop();
        }
    for(int i=0; i<result.size();i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}

//priority_queue 是 C++ 标准库中的一个容器适配器，默认情况下是一个最大堆，但可以通过自定义比较函数来实现最小堆。

 /*int main(){
    vector<int>nums;
    int num;
    while(cin>>num){
        nums.push_back(num);
        if(cin.get() == '\n') break;
    }
    int k;
    cin>>k;
    vector<int>res;
    map<int,int>m;
    multimap<int,int>n;
    if(nums.size()==1) return nums[0];
    for(auto iter : nums){
        m[iter]++;
    }
    for(auto it=m.begin();it!=m.end();it++){
        n.insert(pair<int,int>{it->second,it->first});  //pair 没有指定模板参数，导致编译器无法推断类型。
    }
    for(auto it=n.rbegin();k>0&&it!=n.rend();it++,k--){
        res.push_back(it->second);
    }
    for(int i=0; i<res.size();i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
    return 0;
 }*/