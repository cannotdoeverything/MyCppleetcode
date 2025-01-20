/*题意：反转一个单链表。

示例: 输入: 1->2->3->4->5->NULL 输出: 5->4->3->2->1->NULL*/

#include<iostream>
#include<list>

using namespace std;

class Solution{
private:
    struct ListNode{
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL){}
    };
public:
    ListNode* reverseList(ListNode* head){
        ListNode* cur = head;
        ListNode* pre = nullptr;
        ListNode* temp;
        while(cur){
            temp = cur->next;
            cur->next = pre;
            pre =cur;
            cur = temp;
        }
    return pre;
    }
void test(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    
    cout << "Original list: ";
        printList(head);

    head = reverseList(head);

    cout << "Reversed list: ";
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

