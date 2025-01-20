/*给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。

进阶：你能尝试使用一趟扫描实现吗？*/

#include<iostream>
#include<list>

using namespace std;

class Soultion{
private:
    struct ListNode{
        int val;
        ListNode *next;
        ListNode (int x) : val(x), next(NULL){}
    };
public:
    ListNode* removeN(ListNode* head, int n){
        ListNode *dummyNode = new ListNode(0);
        dummyNode->next = head;
        ListNode *fast = dummyNode;
        ListNode *slow = dummyNode;
        while(n-- && fast != nullptr){
            fast = fast->next;
        }
        while(fast->next !=nullptr){
            slow = slow->next;
            fast = fast->next;
        }
        ListNode *temp = slow->next;
        slow->next = slow->next->next;
        delete temp;
        return dummyNode->next;
      
    } 
void test(){
    int n = 2;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    

    cout << "Original list: ";
        printList(head);

    head = removeN(head,n);

    cout<<"new list: ";
    printList(head);
}

void printList(ListNode* head){
    while(head !=nullptr){
        cout<<head->val;
        if(head->next) cout<<"->";
        head = head->next;
    }
    cout<<endl;
}

};
int main(){
    Soultion sol;
    sol.test();
    return 0;
}