
#include<vector>
#include<iostream>

using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(nullptr),right(nullptr){}
};

//前序遍历
void preorderTraversal(TreeNode *root, vector<int>&res){
        if(root==nullptr) return;
        res.push_back(root->val);
        preorderTraversal(root->left,res);
        preorderTraversal(root->right,res);
}



TreeNode* buildTree(const vector<int>& nums, int index) {
    if (index >= nums.size() || nums[index] == -1) return nullptr; // 使用 -1 表示空节点
    TreeNode* root = new TreeNode(nums[index]);
    root->left = buildTree(nums, 2 * index + 1);
    root->right = buildTree(nums, 2 * index + 2);
    return root;
}
/*
使用 buildTree 函数根据输入的数组构建二叉树。
输入数组中的 -1 表示空节点。
通过索引关系（2 * index + 1 和 2 * index + 2）确定左右子节点的位置*/

int main(){
        vector<int>nums;
        int i;
        while(cin>>i){
            nums.push_back(i);
            if(cin.get()== '\n') break;
        }
        vector<int>res;
        TreeNode* root = buildTree(nums, 1);
        preorderTraversal(root,res);
        for(int i=0; i<res.size();i++){
            cout<<res[i]<<" ";
        }
        cout<<endl;
        return 0; 
}