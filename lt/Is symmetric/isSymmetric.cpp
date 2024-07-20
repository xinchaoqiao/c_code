#include <iostream>
#include "TreeStruct.h"
using namespace std;
//对称二叉树
class Solution {
public:

    //相同树思路
    bool check(TreeNode* p, TreeNode* q) {
        if (!p && !q) {
            return true;
        }
        else if (p && q && p->val == q->val)
            return check(p->left, q->right) && check(p->right, q->left);
        
        else return false;
    }
    bool isSymmetric(TreeNode* root) {
        return check(root->left, root->right);
    }
};
//利用相同树的思路
/*
    将对称二叉树转换为相同树思路
*/