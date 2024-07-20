#include <iostream>
#include "TreeStruct.h"
using namespace std;
TreeNode* CreatTree() {
    TreeNode* root = new TreeNode(0);
    root->left = new TreeNode(20);
    root->right = new TreeNode(10);
    TreeNode* cur = root->left;
    cur->left = new TreeNode(-1);
    cur->right = new TreeNode(-2);
    return root;
}
void preorder(TreeNode* root) {
    cout << root->val << endl;
    if (root->left)
        preorder(root->left);
    if (root->right)
        preorder(root->right);
}
void swap(TreeNode* root) {
    if (!root) {
        return;
    }
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    
    swap(root->left);
    swap(root->right);
}
int main(void)
{
    TreeNode* root = CreatTree();
    preorder(root);
    swap(root->left, root->right);
    cout << "swap after" << endl;
    preorder(root);
    return 0;
}