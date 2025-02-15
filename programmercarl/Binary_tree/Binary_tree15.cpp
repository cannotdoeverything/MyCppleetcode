/*左子叶之和*/

#include<iostream>
#include<queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode (int x) : val(x), left(nullptr), right(nullptr){}
};

//迭代
class Soultion1{
public:
    int sumLeft(TreeNode *root){
        queue<TreeNode*>que;
        int res = 0;
        if(root != nullptr) que.push(root);
        while(!que.empty()){
            TreeNode *node =que.front();
            que.pop();
            if(node->left){
                if(!node->left->left && !node->left->right){
                    res += node->left->val;
                }else{
                    que.push(node->left);
                }
            }
            if(node->right) que.push(node->right); 
        }
        return res;
    }
};

//递归（中序）
class Solution{
    int bfs(TreeNode*root){
        if(root==nullptr) return 0;
        if(!root->left && !root->right) return 0;
        int leftval = bfs(root->left);
        if(root->left && !root->left->left && !root->left->right){
            leftval = root->left->val;
        }
        int rightval = bfs(root->right);
        int sum = leftval + rightval;
        return sum;
    }
public:
    int sumLeft(TreeNode *root){
        return bfs(root);
    }
};

/*路径总和*/
/*
思路1
递归不返回值，注意sum += root->val; 放在判断后
思路2
递归返回结果，注意左右节点递归需要返回if(bfs(root->left,count)) return true;
*/


