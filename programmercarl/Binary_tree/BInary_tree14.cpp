/*二叉树的所有路径
给定二叉树的根节点，按任意顺序，返回所有从根节点到叶子节点到路径
*/

#include<iostream>
#include<vector>
#include<string>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode (int x) : val(x), left(nullptr), right(nullptr){}
};

class Solution{
private:
    void bfs(TreeNode*root,vector<int>&path,vector<string>&res){
        path.push_back(root->val);
        if(root->left==nullptr && root->right ==nullptr){
            string sPath;
            for(int i=0; i<path.size()-1;i++){
                sPath += path[i];
                sPath += "->";
            }
            sPath += path[(path.size()-1)];
            res.push_back(sPath);
            return;
        }
        if(root->left){
            bfs(root->left,path,res);
            path.pop_back();
        }
        if(root->right){
            bfs(root->right,path,res);
            path.pop_back();
        }
    }
public:
    vector<string> bfsPaths(TreeNode* root){
        vector<string>res;
        vector<int>path;
        if(root==nullptr) return res;
        bfs(root,path,res);
        return res;
    }
};