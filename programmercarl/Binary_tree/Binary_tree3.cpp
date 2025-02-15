/*二叉树的统一迭代法

将访问的节点放入栈中，把要处理的节点也放入栈中但是要做标记。

如何标记呢？
方法一：就是要处理的节点放入栈之后，紧接着放入一个空指针作为标记。 这种方法可以叫做空指针标记法。

方法二：加一个 boolean 值跟随每个节点，false (默认值) 表示需要为该节点和它的左右儿子安排在栈中的位次，
true 表示该节点的位次之前已经安排过了，可以收割节点了。 
这种方法可以叫做boolean 标记法，样例代码见下文C++ 和 Python 的 boolean 标记法。 这种方法更容易理解，在面试中更容易写出来
*/

#include<iostream>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode (int x) : val(x),left(nullptr),right(nullptr){}
};

TreeNode *buildTree(vector<int>&nums,int index){
    if(index >=nums.size() || nums[index] == -1) return nullptr;
    TreeNode *root = new TreeNode(nums[index]);
    root->left = buildTree(nums,2*index+1);
    root->right =  buildTree(nums,2*index+2);
    return root;
}

//中序遍历
int main(){
    vector<int>nums;
    int i;
    while(cin>>i){
        nums.push_back(i);
        if(cin.get()=='\n') break;
    }
    vector<int>res;
    stack<TreeNode*>st;
    TreeNode *root = buildTree(nums,0);
    if(root != nullptr) st.push(root);
    while(!st.empty()){
        TreeNode *node = st.top();
        if(node!=nullptr){
            st.pop();   // 将该节点弹出，避免重复操作，下面再将右中左节点添加到栈中
            if(node->right) st.push(node->right);

            st.push(node);  // 添加中节点
            st.push(nullptr); // 中节点访问过，但是还没有处理，加入空节点做为标记。

            if(node->left) st.push(node->left);
        }else{
            st.pop();
            node = st.top();
            st.pop();
            res.push_back(node->val);
        }
    }
    for (auto a :  res) {
        cout << a << " ";
    }
    cout << endl;
    return 0;
}

//前序遍历
int main(){
    vector<int>nums;
    int i;
    while(cin>>i){
        nums.push_back(i);
        if(cin.get()=='\n') break;
    }
    stack<TreeNode*>st;
    vector<int>res;
    TreeNode *node = buildTree(nums,0);
    if(node != nullptr) st.push(node);
    while(!st.empty()){
        TreeNode *root = st.top();
        if(root != nullptr){
            st.pop();
            if(root->right) st.push(root->right);
            if(root->left) st.push(root->left);
            st.push(root);
            st.push(nullptr);
        }else{
            st.pop();
            root = st.top();
            st.pop();
            res.push_back(root->val);
        }
    }
    for (auto a :  res) {
        cout << a << " ";
    }
    cout << endl;
    return 0;
}

//后序遍历
int main(){
    vector<int>nums;
    int i;
    while(cin>>i){
        nums.push_back(i);
        if(cin.get() == '\n') break;
    }
    stack<TreeNode*>st;
    vector<int>res;
    TreeNode *root = buildTree(nums,0);
    if(root != nullptr) st.push(root);
    while(!st.empty()){
        TreeNode *node = st.top();
        if(node !=nullptr){
            st.pop();
            st.push(node);
            st.push(nullptr);
            if(node->right) st.push(node->right);
            if(node->left)  st.push(node->left);
        }else{
            st.pop();
            node = st.top();
            st.pop();
            res.push_back(node->val);
        }
    }
}