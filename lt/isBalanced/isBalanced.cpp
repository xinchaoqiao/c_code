#include <iostream>
using namespace std;
#include "TreeStruct.h"

class Solution {
public:
    int hight(TreeNode* root) {
        if (!root) return 0;
        int leftdepth = hight(root->left);
        int rightdepth = hight(root->right);
        if (leftdepth == -1 || rightdepth == -1 || abs(leftdepth - rightdepth) > 1) {
            return -1;
        }
        return max(leftdepth, rightdepth) + 1;
    }
    bool isBalanced(TreeNode* root) {
        return hight(root) >= 0;
    }
};