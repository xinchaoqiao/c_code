#include <iostream>
using namespace std;
#include "TreeStruct.h"
class Solution {
public:
    //只需要排除其他情况，然后只考虑一个点就可以。
    int minDepth(TreeNode* root) {
        if (!root)return 0;
        if(!root->left) 
            return max(minDepth(root->left), minDepth(root->right)) + 1;
        if (!root->right)
            return max(minDepth(root->left), minDepth(root->right)) + 1;
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};