/*题意：删除链表中等于给定值 val 的所有节点。
示例 1： 输入：head = [1,2,6,3,4,5,6], val = 6 输出：[1,2,3,4,5]
示例 2： 输入：head = [], val = 1 输出：[]
示例 3： 输入：head = [7,7,7,7], val = 7 输出：[]
#*/
#include<iostream>
#include<list>

using namespace std;

class Solution{
private:
    struct ListNode {
    int val;  // 节点上存储的元素
    ListNode *next;  // 指向下一个节点的指针
    ListNode(int x) : val(x), next(NULL) {}  //节点的构造函数
};
public: 
    ListNode* removeElements(ListNode* head, int val){
        if(head==nullptr) return nullptr;
        ListNode* dummyNode = new ListNode(0);
        dummyNode->next = head;
        ListNode* cur = head;
        ListNode* prev = dummyNode;
        while(cur != nullptr){
            if(cur->val == val){
                prev->next = cur->next;
            }else{
                prev = cur;
            }
            cur = cur->next;
        }
        /*ListNode* dummyNode = new ListNode(0);
        dummyNode->next = head;
        ListNode* cur = dummyNode;
        while(cur->next != NULL){
            if(cur->next->val == val){
                ListNode* temp = cur->next;
                cur->next = cur->next->next;
                delete temp;
            }else{
                cur = cur->next;
            }
        }*/
        return dummyNode->next;
    }
void test() {
        // 构造链表：1 -> 2 -> 6 -> 3 -> 4 -> 5 -> 6
        ListNode* head = new ListNode(1);
        head->next = new ListNode(2);
        head->next->next = new ListNode(6);
        head->next->next->next = new ListNode(3);
        head->next->next->next->next = new ListNode(4);
        head->next->next->next->next->next = new ListNode(5);
        head->next->next->next->next->next->next = new ListNode(6);

        int val = 6; // 要删除的值

        // 输出原链表
        cout << "Original list: ";
        printList(head);

        // 删除指定值的节点
        head = removeElements(head, val);

        // 输出修改后的链表
        cout << "Modified list: ";
        printList(head);
    }

    // 打印链表
    void printList(ListNode* head) {
        while (head != nullptr) {
            cout << head->val;
            if (head->next != nullptr) cout << " -> ";
            head = head->next;
        }
        cout << endl;
    }
};
int main(){
    Solution sol;
    sol.test();
    return 0;
}