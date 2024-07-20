#include <iostream>
#include "TreeStruct.h"
#include <vector>
using namespace std;
class Solution {
public:
    void beorder(TreeNode* root, vector<int>& v) {
        if (!root)return;
        if (root->left)
            beorder(root->left,v);
        if (root->right)
            beorder(root->right,v);
        v.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        beorder(root,v);
        return v;
    }
};