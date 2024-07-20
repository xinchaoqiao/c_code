#include <iostream>
#include "TreeStruct.h"
using namespace std;
class Solution {
public:
    //递归思想
    //左右各自遍历
    int getDepth(TreeNode* root) {
        int leftdepth = getDepth(root->left);
        int rightdepth = getDepth(root->right);
        int depth = max(leftdepth, rightdepth) + 1;
        return depth;
    }
    int maxDepth(TreeNode* root) {
        return getDepth(root);
    }
};