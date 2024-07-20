#include <iostream>
#include "TreeStruct_more.h"
using namespace std;
int node_count(TreeNode* root) {
    if (!root) return 0;
    return node_count(root->left) + node_count(root->right) + 1;
}
int main(void) {
    TreeNode* root = creat_tree1();
    cout << node_count(root) << endl;
    return 0;
}