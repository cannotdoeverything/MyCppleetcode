/*
给定一个 N 叉树，返回其节点值的层序遍历。（即从左到右，逐层遍历）。
树的序列化输入是用层序遍历，每组子节点都由 null 值分隔（参见示例）*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Node {
public:
    int val; // 节点的值
    vector<Node*> children; // 子节点列表

    // 默认构造函数
    Node() : val(0) {}

    // 带值的构造函数
    Node(int _val) : val(_val) {}

    // 带值和子节点的构造函数
    Node(int _val, vector<Node*> _children) : val(_val), children(_children) {}
};

// 层序遍历
vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>> res;
    if (!root) return res; // 如果根节点为空，直接返回

    queue<Node*> que;
    que.push(root);

    while (!que.empty()) {
        int size = que.size();
        vector<int> vec;

        for (int i = 0; i < size; i++) {
            Node* node = que.front();
            que.pop();
            vec.push_back(node->val);

            for (Node* child : node->children) {
                if (child) que.push(child);
            }
        }

        res.push_back(vec);
    }

    return res;
}



// 打印层序遍历结果
void printLevelOrder(const vector<vector<int>>& res) {
    for (const auto& level : res) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    // 构建一个简单的多叉树
    Node* root = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);
    Node* node6 = new Node(6);

    root->children = {node2, node3, node4};
    node3->children = {node5, node6};

    // 进行层序遍历
    vector<vector<int>> res = levelOrder(root);

    // 打印结果
    printLevelOrder(res);

    // 释放内存（可选）
    delete root;
    delete node2;
    delete node3;
    delete node4;
    delete node5;
    delete node6;

    return 0;
}


