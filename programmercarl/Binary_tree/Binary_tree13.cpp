

//二叉树节点的深度：指从根节点到该节点到最长简单路径边的条数
//二叉树节点的高度：指从该节点到叶子节点的最长简单路径边的条数。根节点的高度是最大深度
//求深度：前序
//求高度：只能后序

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
    int bfs(TreeNode*root){
        if(root== nullptr) return 0;
        int leftHeight = bfs(root->left);
        if(leftHeight==-1){
            return -1;
        }
        int rightHeight = bfs(root->right);
        if(rightHeight==-1){
            return -1;
        }
        int res;
        if(abs(leftHeight-rightHeight)>1){
            return -1;
        }else{
            res = 1+max(leftHeight,rightHeight);
        }
        return res;
    }
public:
    bool isAVL(TreeNode*root){
        if(root==nullptr) return true;
        return bfs(root)==-1 ? false:true;
    }
};