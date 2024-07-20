#include <iostream>
#include "TreeStruct.h"
#include <vector>
using namespace std;
//思路，以中间节点作为根节点 时间复杂度O（n）每个数字只访问一次
class Solution {
public:
    TreeNode* helper(vector<int>& nums, int left, int right) {
        //递归基
        if (left > right)
            return nullptr;
        //创建节点
        int mid = (left + right) / 2;
        TreeNode* root = new TreeNode(nums[mid]);


        //左右孩子赋值
        root->left = helper(nums, left, mid - 1);
        root->right = helper(nums, mid + 1, right);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        return helper(nums, left, right);
    }
};