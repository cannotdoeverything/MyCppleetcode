/*二叉树的最小深度*/

#include<iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode (int x) : val(x), left(nullptr),right(nullptr){} 
};

class Solution1 {
int bfs(TreeNode *root){
        if(root==nullptr) return 0;
        int leftdepth = bfs(root->left);
        int rightdepth = bfs(root->right);
        if(root->left != nullptr && root->right == nullptr){
            return leftdepth+1;
        }
        if(root->left == nullptr && root->right != nullptr){
            return rightdepth+1;
        }
        int depth = 1 + min(leftdepth,rightdepth);
        return depth;
    }
public:
    int minDepth(TreeNode* root) {
        return bfs(root);
    }
};

class Solution{
    int res;
private:
    void bfs(TreeNode*root, int depth){

        if(root->left == nullptr && root->right== nullptr){
            res = min(depth,res);
        }
        if(root->left){
            bfs(root->left,depth+1);
        }
        if(root->right){
            bfs(root->right,depth+1);
        }
    }
public:
    int minDepth(TreeNode* root){
        res = INT_MAX;
        if(root== 0) return 0;
        bfs(root,1);
    }
};