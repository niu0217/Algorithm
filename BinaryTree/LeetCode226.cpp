/* ************************************************************************
> File Name:     LeetCode226.cpp
> Author:        niu0217
> Created Time:  三  2/21 16:55:17 2024
 ************************************************************************/

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
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) {
            return nullptr;
        }
        TreeNode* leftSubTree = invertTree(root->left);
        TreeNode* rightSubTree = invertTree(root->right);
        root->left = rightSubTree;
        root->right = leftSubTree;
        return root;
    }
};
