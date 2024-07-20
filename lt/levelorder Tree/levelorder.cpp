#include <iostream>
#include <queue>
#include "TreeStruct.h"
using namespace std;

TreeNode* self_creat(void) {
    TreeNode* root = new TreeNode(10);
    TreeNode* cur = root;
    cur->left = new TreeNode(20);
    cur->right = new TreeNode(30);
    cur = root->left;
    cur->left = new TreeNode(40);
    return root;
}
int levelorder(TreeNode* root) {
    if (!root) return 0;

    queue<TreeNode*> q;
    q.push(root);
    int level;
    //每个队列节点数目就是每一层节点数目
    while (!q.empty())
    {
        int curlevelsize = q.size();
        level++;  //每一层一个队列，一个while循环代表一层所以level的值可以代表树的深度
        for (int i = 0; i < curlevelsize;i++) {//遍历当前层 如果只需要层次遍历的话可以不使用for循环
            TreeNode* cur = q.front();
            cout << cur->val << endl;// 层次遍历打印位置
            q.pop();
            if (cur->left)
                q.push(cur->left);
            if (cur->right)
                q.push(cur->right);
        }
    }
    return level;
}
int main(void) {

    TreeNode* root = self_creat();
    cout << levelorder(root) << endl;
    return 0;
}
//单一实现层次遍历
// int levelorder(TreeNode* root) {
//     if (!root) return 0;
//     queue<TreeNode*> q;
//     q.push(root);
//     int level;
//     //每个队列节点数目就是每一层节点数目
//     while (!q.empty())
//     {
//             TreeNode* cur = q.front();
//             cout << cur->val << endl;// 层次遍历打印
//             q.pop();
//             if (cur->left)
//                 q.push(cur->left);
//             if (cur->right)
//                 q.push(cur->right);
//     }
//     return level;
// }