#include <iostream>
#include <vector>
#include "TreeStruct.h"
using namespace std;
//相同树
class Solution {
public:
    //两个树的根节点
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!q && !p) {
            return true;
        }    
        else if (p && q && p->val == q->val) {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
        else return false;
    }
};