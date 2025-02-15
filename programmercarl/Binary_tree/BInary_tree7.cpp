/*给定一个 完美二叉树 ，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。

初始状态下，所有 next 指针都被设置为 NULL。*/

#include<iostream>
#include<queue>
#include<vector>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


//层序遍历
int main(){
    queue<Node*>que;
        if(root != nullptr) que.push(root);
        while(!que.empty()){
            int size = que.size();
            Node *nodepre;
            Node *node;
            for(int i=0; i<size; i++){
                if(i==0){
                    nodepre = que.front();
                    que.pop();
                    node = nodepre;
                }else{
                    node = que.front();
                    que.pop();
                    nodepre->next=node;
                    nodepre = nodepre->next;
                }
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            nodepre->next = nullptr;
        }
        return root;
}