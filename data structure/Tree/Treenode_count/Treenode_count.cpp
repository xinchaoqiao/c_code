#include <iostream>
#include "TreeStruct.h"
using namespace std;
TreeNode* creat_tree() {
    TreeNode* root = new TreeNode(0);
    root->left = new TreeNode(20);
    root->right = new TreeNode(10);
    TreeNode* cur = root->left;
    cur->left = new TreeNode(-1);
    cur->right = new TreeNode(-2);
    return root;
}
int tree_count(TreeNode* root) {
    int count;
    if (!root) return 0;
   
    return tree_count(root->left) + tree_count(root->right) +1;
}
int main(void)
{
    TreeNode* root = creat_tree();
    cout << tree_count(root) << endl;
    return 0;
}