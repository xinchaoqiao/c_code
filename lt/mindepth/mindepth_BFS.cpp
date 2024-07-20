#include <iostream>
using namespace std;
#include <queue>
#include "TreeStruct.h"
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        queue<pair<TreeNode*, int>> q;
        q.emplace(root, 1);//插入根节点和对应的depth
        while (!q.empty())
        {
            TreeNode* cur = q.front().first;
            int depth = q.front().second;
            q.pop();
            if (!cur->left && !cur->right) return depth;
            if (cur->left) q.emplace(cur->left, depth + 1);
            if (cur->right) q.emplace(cur->right, depth + 1);
        }
        return 0;
    }
};