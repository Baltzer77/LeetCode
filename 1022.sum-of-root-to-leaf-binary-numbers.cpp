/*
 * @lc app=leetcode id=1022 lang=cpp
 *
 * [1022] Sum of Root To Leaf Binary Numbers
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int traverse(TreeNode* node, int val) {
        if(node == nullptr) return 0;

        val = (val << 1) | node->val;

        if(node->left == nullptr && node->right == nullptr) return val;

        return traverse(node->left, val) + traverse(node->right, val);
    }

    int sumRootToLeaf(TreeNode* root) {
        return traverse(root, 0);
    }
};
 // @lc code=end

