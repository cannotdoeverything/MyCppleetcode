/*给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表没有交点，返回 null 。
题目数据 保证 整个链式结构中不存在环。

注意，函数返回结果后，链表必须 保持其原始结构 。*/
 #include<iostream>
 #include<list>

 using namespace std;

 class Solution{
private:
    struct ListNode{
        int val;
        ListNode *next;
        ListNode (int x) : val(x), next(nullptr){}
    };
public:
    ListNode *getIntersection(ListNode *headA, ListNode *headB){
        ListNode *curA =headA;
        ListNode *curB = headB;
        int size_A =0, size_B=0;
        while(curA){
            curA = curA->next;
            size_A++;
        }
        while(curB){
            curB = curB->next;
            size_B++;
        }
        curA = headA;
        curB = headB;
        if(size_A<size_B){
            swap(size_A,size_B);
            swap(curA,curB);
        }
        int gap = size_A-size_B;
        while(gap--){
            curA = curA->next;
        }
        while(curA !=  nullptr){
            if(curA==curB) return curA;
            curA =curA->next;
            curB =curB->next;
        }
        return nullptr;

/*
求两个链表交点节点的指针。 这里同学们要注意，交点不是数值相等，而是指针相等
问：[4,1,8,4,5]和[5,0,1,8,4,5]的相交节点为什么不是1啊？
答：该题交点不是数值相等，而是指针相等！注意是指针哦！
假设指针P1指向[4,1,8,4,5]里的1，地址是001。
假设指针P2指向[5,0,1,8,4,5]里的1，地址是002。
虽然两个指针指向的节点值相同，但是地址不同，所以这并不是同一个节点，也就不是题目的交点。
*/
        /*if(size_A>size_B){
            n =size_A-size_B;
            while(n--){
                curA = curA->next;
            }
            while(curA != nullptr && curB!=nullptr){
                if(curA==curB) return curA;
                curA = curA->next;
                curB = curB->next;
            }
        } else{
            n =size_B-size_A;
            while(n--)
            curB =curB->next;
            while(curA != nullptr && curB!=nullptr){
                if(curA==curB) return curB;
                curA = curA->next;
                curB = curB->next;
            }
        } 
        return nullptr;*/
    }  
 };