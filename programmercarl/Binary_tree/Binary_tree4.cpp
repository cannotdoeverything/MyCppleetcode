/*层序遍历
给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。
*/

/*需要借用一个辅助数据结构即队列来实现，队列先进先出，符合一层一层遍历的逻辑，而用栈先进后出适合模拟深度优先遍历也就是递归的逻辑。

而这种层序遍历方式就是图论中的广度优先遍历，只不过我们应用在二叉树上。
*/
#include<iostream>
#include<queue>
#include<vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode (int x):val(x),left(nullptr),right(nullptr){}
};

TreeNode *bulidTree(vector<int>&nums,int index){
    if(index == -1 || index>nums.size()) return nullptr;
    TreeNode *root = new TreeNode(nums[index]);
    root->left = bulidTree(nums,2*index+1);
    root->right = bulidTree(nums,2*index+2);
    return root;
}


//迭代法
int main(){
    vector<int>nums;
    int i;
    while(cin>>i){
        nums.push_back(i);
        if(cin.get()=='\n') break;
    }

    vector<vector<int>>res;
    queue<TreeNode*>que;
    TreeNode* root = bulidTree(nums,0);
    if(root != nullptr) que.push(root);
    while(!que.empty()){
        int size = que.size();
        vector<int>vec;
        for(int i=0;i<size;i++){
            TreeNode *node = que.front();
            que.pop();
            vec.push_back(node->val);
            if(node->left) que.push(node->left);
            if(node->right) que.push(node->right);
        }
        res.push_back(vec);
    }


}

//递归法
void levelOrder(TreeNode* cur, vector<vector<int>>&res, int depth){
    
    if(cur == nullptr) return;
    if(res.size()==depth) res.push_back(vector<int>()); //在 res 中添加一个新的空子数组，用于存储当前深度的节点值
    res[depth].push_back(cur->val);
    levelOrder(cur->left,res,depth+1);
    levelOrder(cur->right,res,depth+1);
}

int main(){
    vector<int>nums;
    int i;
    while(cin>>i){
        nums.push_back(i);
        if(cin.get()=='\n') break;
    }
    TreeNode *root = bulidTree(nums,0);
    vector<vector<int>> res;
    int depth = 0;
    levelOrder(root,res,depth);
    for (const auto& level : res) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
