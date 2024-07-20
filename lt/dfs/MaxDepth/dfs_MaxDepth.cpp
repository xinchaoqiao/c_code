#include <iostream>
#include "TreeStruct.h"
using namespace std;
//这里的dfs在Tree中有另外一份
class Solution {
public:
    //dfs
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};