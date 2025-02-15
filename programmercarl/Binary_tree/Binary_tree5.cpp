/*给定一个二叉树的 根节点 root，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值
*/

#include<iostream>
#include<queue>
#include<vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode (int x):val(x),left(nullptr),right(nullptr){}
};

TreeNode *buildTree(vector<int>nums,int index){
    if(index == -1||index>nums.size()) return nullptr;
    TreeNode *root = new TreeNode(nums[0]);
    root->left = buildTree(nums,2*index+1);
    root->right = buildTree(nums,2*index+2);
}

int main(){
    int i;
    vector<int>nums;
    while(cin>>i){
        nums.push_back(i);
        if(cin.get()=='/n') break;
    }
    TreeNode *root = buildTree(nums,0);
    vector<int>res;
    queue<TreeNode*>que;
    if(root != nullptr) que.push(root);
    while(!que.empty()){
        int size = que.size();
        for(int i=0; i<size; i++){
            TreeNode *node = que.front();
            que.pop();
            if(i==size-1) res.push_back(node->val);
            if(node->left) que.push(node->left);
            if(node->right) que.push(node->right);
        }
    }

}


void Rightview(vector<int>&res,TreeNode*root,int depth){
    if(root == nullptr) return;
    if(depth == res.size()) res.push_back(root->val);
    Rightview(res,root->right,depth+1);
    Rightview(res,root->left,depth+1);
}
int main(){
    int i;
    vector<int>nums;
    while(cin>>i){
        nums.push_back(i);
        if(cin.get()=='/n') break;
    }
    TreeNode *root = buildTree(nums,0);
    vector<int>res;
    int depth = 0;
    Rightview(res,root,depth);

}

