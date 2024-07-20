#include <iostream>
using namespace std;
#include "TreeStruct_more.h"
TreeNode* CreatTree_first() {
    TreeNode* root = new TreeNode(0);
    root->left = new TreeNode(20);
    root->right = new TreeNode(10);
    TreeNode* cur = root->left;
    cur->left = new TreeNode(-1);
    cur->right = new TreeNode(-2);
    return root;
}
TreeNode* CreatTree_second() {
    TreeNode* root = new TreeNode(0);
    root->left = new TreeNode(20);
    root->right = new TreeNode(10);
    TreeNode* cur = root->left;
    cur->left = new TreeNode(-1);
    cur->right = new TreeNode(-2);
    return root;
}
bool same_tree(TreeNode* p,TreeNode* q) {
    if (!q && !p) {
        return true;
    }
    else if (!p || !q) {
        return false;
    }
    else if (p->val != q->val) return false;
    else return same_tree(p->left, q->left) && same_tree(p->right, q->right);

}
int main(void)
{
    TreeNode* t1, * t2;

    t1 = creat_tree1();
    t2 = creat_tree2();
    if (same_tree(t1, t2)) {
        cout << "两棵树相等" << endl;
    }
    else cout << "两棵树不相等" << endl;
    return 0;
}