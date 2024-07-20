#include <iostream>
#include "TreeStruct_more.h"
using namespace std;
bool same_tree(TreeNode* r1, TreeNode* r2) {
    if (!r1 && r2) return true;
    else if (!r1 || !r2) return false;
    else if (r1->val != r2->val) return false;
    else return same_tree(r1->left, r2->left) && same_tree(r1->right, r2->right);
}
int main(void) {
    TreeNode* root1 = creat_tree1();
    TreeNode* root2 = creat_tree2();
    if (same_tree(root1, root2) == true) {
        cout << "两棵树相同" << endl;
    }
    else cout << "两棵树不同" << endl;
    return 0;
}