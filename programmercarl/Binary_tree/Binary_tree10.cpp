/*给定一个二叉树，找出其最大深度。
二叉树的深度为根节点到最远叶子节点的最长路径上的节点数*/


/*
二叉树节点的深度：指从根节点到该节点的最长简单路径边的条数或者节点数（取决于深度从0开始还是从1开始）
二叉树节点的高度：指从该节点到叶子节点的最长简单路径边的条数或者节点数（取决于高度从0开始还是从1开始）

而根节点的高度就是二叉树的最大深度*/

#include<iostream>
#include<queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode (int x) : val(x), left(nullptr),right(nullptr){} 
};


class Soultion{
private:
    int bfs(TreeNode *root){
        if(root==nullptr) return 0;
        int leftdepth = bfs(root->left);
        int rightdepth = bfs(root->right);
        int depth = 1+max(leftdepth,rightdepth);
        return depth;
    }
public:
    int depthMax(TreeNode *root){
        return bfs(root);
    }
};

int main(){
    TreeNode *root = new TreeNode(1);
    Soultion sol;
    int maxdepth = sol.depthMax(root);
    cout<<maxdepth<<endl;
    return 0;
}



class Solution2 {
public:
    int result;
    void getdepth(TreeNode* node, int depth) {
        result = depth > result ? depth : result; // 中

        if (node->left == NULL && node->right == NULL) return ;

        if (node->left) { // 左
            depth++;    // 深度+1
            getdepth(node->left, depth);
            depth--;    // 回溯，深度-1,重要，否则return错误
        }
        if (node->right) { // 右
            depth++;    // 深度+1
            getdepth(node->right, depth);
            depth--;    // 回溯，深度-1
        }
        return ;
    }
    int maxDepth(TreeNode* root) {
        result = 0;
        if (root == NULL) return result;
        getdepth(root, 1);
        return result;
    }
};



//N叉树的遍历
class Soultion3{
public:
    int Maxdepth(Node *root){
        if(root==nullptr) return 0;
        int depth = 0;
        for(int i=0; i<root->children.size();i++){
            depth = max(depth,Maxdepth(root->children[i]));
        }
        return depth+1;
    }
};


class Solution4{
public:
    int Maxdepth(Node *root){
        queue<Node*>que;
        int depth = 0;
        if(root != nullptr) que.push(root);
        while(!que.empty()){
            int size = que.size();
            depth++;
            for(int i=0;i<size;i++){
                Node *node = que.front();
                que.pop();
                for(int j=0;j<node->children.size();j++){
                    if(node->children[j]) que.push(node->children[j]);
                }
            }
        }
        return depth;
    }
};