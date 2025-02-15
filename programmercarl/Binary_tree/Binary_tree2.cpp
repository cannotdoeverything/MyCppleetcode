/*二叉树的迭代遍历
*/

#include<iostream>
#include<stack>
#include<queue>
#include<vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr),right(nullptr){}
};

TreeNode* buildTree(){
    int val;
    cin>>val;
    if(val==-1) return nullptr;

    TreeNode *root = new TreeNode(val);
    queue<TreeNode*>q;
    q.push(root);

    while(!q.empty()){
        TreeNode *cur = q.front();
        q.pop();

        cin>>val;
        if(val !=-1){
            cur->left = new TreeNode(val);
            q.push(cur->left);
        }
        cin>>val;
        if(val!=-1){
            cur->right = new TreeNode(val);
            q.push(cur->right);
        }
    }
    return root;
};


//前序遍历
int  main(){
    stack<TreeNode*>st;
    vector<int>result;
    TreeNode *root = buildTree();
    if(root != nullptr){
        st.push(root);
    }
    while(!st.empty()){
        TreeNode *node = st.top();
        st.pop();
        result.push_back(node->val);

        if(node->right) st.push(node->right);
        if(node->left) st.push(node->left);
    }
    for(int i=0; i<result.size();i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}

//中序遍历
int main(){
    vector<int>res;
    stack<TreeNode*>st;
    TreeNode *root = buildTree();
    TreeNode *cur = root;
    while(cur != nullptr || !st.empty()){
        if(cur != nullptr){
            st.push(cur);
            cur = cur->left;
        }else{
            cur = st.top();
            st.pop();
            res.push_back(cur->val);
            cur = cur->right;
        }
    }
}

//后序遍历
//先序遍历的代码顺序，就变成中右左的遍历顺序，然后在反转result数组，输出的结果顺序就是左右中了

int main(){
    stack<TreeNode*>st;
    vector<int>res;
    TreeNode *root = buildTree();
    if(root != nullptr) st.push(root);
    while(!st.empty()){
        TreeNode *node = st.top();
        st.pop();
        res.push_back(node->val);
        if(node->left) st.push(root->left);
        if(node->right) st.push(root->right);
    }
    reverse(res.begin(),res.end());

}