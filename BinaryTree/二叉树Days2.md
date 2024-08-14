# 二叉树Days2

## [226. 翻转二叉树](https://leetcode.cn/problems/invert-binary-tree/)

```c++
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
        if (root == nullptr)
        {
            return nullptr;
        }
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
```

## [101. 对称二叉树](https://leetcode.cn/problems/symmetric-tree/)

```c++
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
    bool isSame(TreeNode *rootL, TreeNode *rootR) {
       if (rootL == nullptr && rootR != nullptr) {
        return false;
       }
       if (rootL != nullptr && rootR == nullptr) {
        return false;
       }
       if (rootL == nullptr && rootR == nullptr) {
        return true;
       }
       bool condition1 = rootL->val == rootR->val;
       bool condition2 = isSame(rootL->left, rootR->right);
       bool condition3 = isSame(rootL->right, rootR->left);
       return condition1 && condition2 && condition3;
    }
public:
    bool isSymmetric(TreeNode* root) {
        return isSame(root, root);
    }
};
```

## [104. 二叉树的最大深度](https://leetcode.cn/problems/maximum-depth-of-binary-tree/)

```c++
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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int leftLen = maxDepth(root->left);
        int rightLen = maxDepth(root->right);
        return max(leftLen, rightLen) + 1;   
    }
};
```

## [111. 二叉树的最小深度](https://leetcode.cn/problems/minimum-depth-of-binary-tree/)

```c++
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
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        if (root->left == nullptr && root->right != nullptr) {
            return minDepth(root->right) + 1;
        }
        if (root->left != nullptr && root->right == nullptr) {
            return minDepth(root->left) + 1;
        }
        int leftLen = minDepth(root->left);
        int rightLen = minDepth(root->right);
        return min(leftLen, rightLen) + 1;
    }
};
```

