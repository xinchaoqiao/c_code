#include <iostream>
#include "TreeStruct.h"
using namespace std;
class Solution {
public:
    //dfs
    int maxDepth(TreeNode* root) {
        //递归基
        if (!root) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};