/*假设链表中的所有节点下标从 0 开始。
在链表类中实现这些功能：
get(index)：获取链表中第 index 个节点的值。如果索引无效，则返回-1。
addAtHead(val)：在链表的第一个元素之前添加一个值为 val 的节点。插入后，新节点将成为链表的第一个节点。
addAtTail(val)：将值为 val 的节点追加到链表的最后一个元素。
addAtIndex(index,val)：在链表中的第 index 个节点之前添加值为 val  的节点。如果 index 等于链表的长度，则该节点将附加到链表的末尾。如果 index 大于链表长度，则不会插入节点。如果index小于0，则在头部插入节点。
deleteAtIndex(index)：如果索引 index 有效，则删除链表中的第 index 个节点。*/

#include<iostream>
#include<list>
#include<vector>

using namespace std;

class MyLinkedList {
public:
    struct LinkedNode {
    int val;  // 节点上存储的元素
    LinkedNode *next;  // 指向下一个节点的指针
    LinkedNode(int val) : val(val), next(nullptr) {}  //节点的构造函数
};
    MyLinkedList(){
      _dummyNode = new LinkedNode(0);
      _size = 0;
    }
    
    int get(int index) {
        if(index > (_size - 1) || index<0){
            return -1;
        }
        LinkedNode *cur = _dummyNode->next;
        while(index--){
            cur = cur->next;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        newNode->next = _dummyNode->next;   //
        _dummyNode->next = newNode;
        _size++;
        
    }
    
    void addAtTail(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* cur = _dummyNode;
        while(cur->next != nullptr){
            cur = cur->next;
        }
        cur->next = newNode;
        _size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index<0) index = 0;
        if(index>_size){
            return;
        }
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* cur = _dummyNode;
        while (index--){
                cur = cur->next;
            }
            newNode->next = cur->next;
            cur->next = newNode;
            _size++;
        }

    void deleteAtIndex(int index) {
        if(index<0 || index>(_size-1)){
            return;
        }
        LinkedNode* cur = _dummyNode;
        while(index--){
            cur = cur->next;
        }
        LinkedNode* temp = cur->next;
        cur->next = cur->next->next;
        delete temp;
        _size--;
    }
    void printLinkedList(){
        LinkedNode* cur = _dummyNode;
        while(cur->next != nullptr){
            cout<<cur->next->val<<" ";
            cur = cur->next;
        }
        cout<<endl;
    }

private:
    int _size;
    LinkedNode* _dummyNode;
};

int main() {
    MyLinkedList linkedList;
    linkedList.addAtHead(1);
    linkedList.addAtTail(3);
    linkedList.addAtIndex(1, 2); // 链表变为 1->2->3
    linkedList.printLinkedList();

    cout << "Get index 1: " << linkedList.get(1) << endl; // 返回 2

    linkedList.deleteAtIndex(1); // 链表变为 1->3
    linkedList.printLinkedList();

    linkedList.deleteAtIndex(0); // 链表变为 3
    linkedList.printLinkedList();

    return 0;
}