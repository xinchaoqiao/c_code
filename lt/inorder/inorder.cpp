#include <iostream>
#include "TreeStruct.h"
#include <vector>
using namespace std;
class Solution {
public:
    void inorder(TreeNode* root, vector<int>& res) {
        if (!root)return;
        if (root->left)
            inorder(root->left, res);
        res.push_back(root->val);
        if (root->right)
            inorder(root->right, res);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }
};