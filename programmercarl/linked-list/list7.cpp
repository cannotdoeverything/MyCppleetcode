/*题意： 给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
为了表示给定链表中的环，使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。
说明：不允许修改给定的链表*/

#include<iostream>
#include<list>
#include<unordered_set>

using namespace std;
class Solution{
private:
    struct ListNode
    {
        int val;
        ListNode *next;
        ListNode (int x) : val(x), next(nullptr){} 
    };
public: 
/*那么相遇时： slow指针走过的节点数为: x + y， fast指针走过的节点数：x + y + n (y + z)，n为fast指针在环内走了n圈才遇到slow指针， （y+z）为 一圈内节点的个数A。
因为fast指针是一步走两个节点，slow指针一步走一个节点， 所以 fast指针走过的节点数 = slow指针走过的节点数 * 2：
(x + y) * 2 = x + y + n (y + z)
两边消掉一个（x+y）: x + y = n (y + z)因为要找环形的入口，那么要求的是x，因为x表示 头结点到 环形入口节点的的距离。
所以要求x ，将x单独放在左面：x = n (y + z) - y ,
再从n(y+z)中提出一个 （y+z）来，整理公式之后为如下公式：x = (n - 1) (y + z) + z 注意这里n一定是大于等于1的，因为 fast指针至少要多走一圈才能相遇slow指针。

这个公式说明什么呢？
先拿n为1的情况来举例，意味着fast指针在环形里转了一圈之后，就遇到了 slow指针了。
当 n为1的时候，公式就化解为 x = z
从头结点出发一个指针，从相遇节点 也出发一个指针，这两个指针每次只走一个节点， 那么当这两个指针相遇的时候就是 环形入口的节点*/
    ListNode *findCycle(ListNode *head){
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast !=nullptr && fast->next !=nullptr){ //这个条件很重要
            slow=slow->next;
            fast=fast->next->next;
        if(slow==fast){
        ListNode *index1 = head;
        ListNode *index2 = slow;
        while(index1 != index2){
            index1 =index1->next;
            index2 =index2->next;
        }
        return index1;
        }
    }
    return nullptr;
}
    /*unordered_set<ListNode*> hashset;
    ListNode *cur = head;
    while(cur != nullptr){
        if(hashset.find(cur) != hashset.end()){ //如果找到了，返回是一个指向 target 的迭代器
            return cur;
        }
        hashset.insert(cur);
        cur = cur->next;
    }
    return nullptr;
    }*/

void printList(ListNode* head, int limit = 10) {
    ListNode* cur = head;
    while (cur != nullptr && limit--) {
        cout << cur->val;
        if (cur->next) cout << " -> ";
        cur = cur->next;
    }
    if (cur != nullptr) cout << " (cycle detected)";
    cout << endl;
}

void test() {
    // 创建链表 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // 打印初始链表
    cout << "Original list: ";
    printList(head);

    // 创建环：让节点 5 的 next 指向节点 3
    head->next->next->next->next->next = head->next->next;
    ListNode* cycleNode = findCycle(head);
    if (cycleNode) {
        cout << "Cycle detected at node with value: " << cycleNode->val << endl;
    } else {
        cout << "No cycle detected." << endl;
    }
}
 
};
int main(){
    Solution sol;
    sol.test();
    return 0;
}