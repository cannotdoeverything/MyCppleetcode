/*给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。*/
#include<iostream>
#include<list>

using namespace std;

class Solution{
private:
    struct ListNode{
        int val;
        ListNode *next;
        ListNode (int x) : val(x), next(NULL){}
    };
public:
    ListNode *swapPairs(ListNode *head){
        ListNode *dummyHead = new ListNode(0);
        ListNode *cur = dummyHead;
        dummyHead->next = head;
        ListNode *temp1;
        ListNode *temp2;
        while(cur->next !=nullptr && cur->next->next != nullptr){
            temp1 = cur->next;
            temp2 = cur->next->next->next;
            cur->next = cur->next->next;
            cur->next->next = temp1;
            cur->next->next->next = temp2;
            cur = cur->next->next;
        }
        return dummyHead->next;

        /*if(head == nullptr || head->next == nullptr) return head;
        ListNode *node1 = head;
        ListNode *node2 = head->next;
        ListNode *node3 = head->next->next;
        node1->next = swapPairs(node3);
        node2->next = node1;

        return node2;
        递归*/
    }
void test(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    cout << "Original list: ";
        printList(head);

    head  = swapPairs(head);

    cout << "swapPairs list: ";
        printList(head);

}
void printList(ListNode *head){
    while(head){
        cout<<head->val;
        if(head->next != nullptr) cout<<"->";
        head = head->next;
    }
    cout<<endl;
}
};

int main(){
    Solution sol;
    sol.test();
    return 0;
}