#pragma once
#include <iostream>
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() :val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x,TreeNode* left,TreeNode* right) :val(x), left(left), right(right) {}
};
TreeNode* creat_tree1() {
    TreeNode* root = new TreeNode(0);
    root->left = new TreeNode(20);
    root->right = new TreeNode(10);
    TreeNode* cur = root->left;
    cur->left = new TreeNode(-1);
    cur->right = new TreeNode(-2);
    return root;
}
/*
树结构
            0
    20            10
-1      -2
总共5个节点
*/
TreeNode* creat_tree2() {
    TreeNode* root = new TreeNode(0);
    root->left = new TreeNode(20);
    root->right = new TreeNode(30);
    TreeNode* cur = root->left;
    cur->left = new TreeNode(-1);
    cur->right = new TreeNode(-2);
    return root;
}
/*
树结构
            0
    20            30
-1      -2
总共5个节点
*/