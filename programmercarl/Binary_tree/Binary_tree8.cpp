/*翻转二叉树*/
#include<stack>
#include<iostream>


using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode (int x) : val(x),left(nullptr),right(nullptr){}
};

TreeNode* buildTree(vector<int>&nums,int index){
    if(index >=nums.size() || nums[index] == -1) return nullptr;
    TreeNode *root = new TreeNode(nums[index]);
    root->left = buildTree(nums,2*index+1);
    root->right =  buildTree(nums,2*index+2);
    return root;
}


//前序递归
class Solution1 {
    void invert(TreeNode *cur){
        if(cur == nullptr) return;
        swap(cur->left,cur->right);
        invert(cur->left);
        invert(cur->right);
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        invert(root);
        return root;
    }
};


//迭代法
class Solution2 {
public:
    TreeNode* invertTree(TreeNode* root) {
        stack<TreeNode*>st;
        if(root!=nullptr) st.push(root);
        while(!st.empty()){
            TreeNode *node = st.top();
            if(node!=nullptr){
                st.pop();
                swap(node->right,node->left);
                if(node->right) st.push(node->right);
                if(node->left) st.push(node->left);
                st.push(node);
                st.push(nullptr);
            }else{
                st.pop();
                node = st.top();
                st.pop();
            }
        }
        return root;
    }
};

int main(){
    vector<int>nums;
    int i;
    while(cin>>i){
        nums.push_back(i);
        if(cin.get()=='/n') break;
    }
    TreeNode *root = buildTree(nums,0);
}

