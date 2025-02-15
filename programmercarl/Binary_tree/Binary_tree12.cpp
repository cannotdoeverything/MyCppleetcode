/*二叉树的节点个数*/

#include<iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode (int x) : val(x), left(nullptr), right(nullptr){}
};

class Solution{
private:
    int bfs(TreeNode* cur){
        if(cur == 0) return 0;
        int leftnode = bfs(cur->left);
        int rightnode = bfs(cur->right);
        int nodes = leftnode+rightnode+1;
        return nodes;
    }
public:
    int countNodes(TreeNode* root){
        return bfs(root);
    }
};

//完全二叉树

/*
终止条件添加
TreeNode *left = root->left;
TreeNode *right = root->right;
int leftdepth = 0.rightdepth = 0;
while(left){
    left =left->left;
    leftdepth++;
}
while(right){
    right = right->right;
    rightdepth++
}
if(leftdepth==rightdepth){
    return (2<<leftdepth) -1;
}
*/