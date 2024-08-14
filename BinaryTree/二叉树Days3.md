# 二叉树Days3

## [110. 平衡二叉树](https://leetcode.cn/problems/balanced-binary-tree/)

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
    int getDepth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        int leftLen = getDepth(root->left);
        int rightLen = getDepth(root->right);
        return max(leftLen, rightLen) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        bool condition1 = abs(getDepth(root->left) - getDepth(root->right)) <= 1;
        bool condition2 = isBalanced(root->left);
        bool condition3 = isBalanced(root->right);
        return condition1 && condition2 && condition3;
    }
};
```

## [257. 二叉树的所有路径](https://leetcode.cn/problems/binary-tree-paths/)

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
    void traversal(TreeNode *cur, string path, vector<string> &result) {
        path += to_string(cur->val);
        if (cur->left == nullptr && cur->right == nullptr) {
            result.push_back(path);
            return;
        }
        if (cur->left) {
            path += "->";
            traversal(cur->left, path, result);
            path.pop_back();
            path.pop_back();
        }
        if (cur->right) {
            path += "->";
            traversal(cur->right, path, result);
            path.pop_back();
            path.pop_back();
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        vector<string> result;
        traversal(root, "", result);
        return result;
    }
};
```

## [404. 左叶子之和](https://leetcode.cn/problems/sum-of-left-leaves/)

+ 递归

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
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        if (root->left == nullptr && root->right == nullptr) {
            return 0;
        }
        int leftValue = sumOfLeftLeaves(root->left);
        if (root->left && !root->left->left && !root->left->right) {
            leftValue = root->left->val;
        }
        int rightValue = sumOfLeftLeaves(root->right);
        int sum = leftValue + rightValue;
        return sum;
    }
};
```

+ 迭代

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
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        stack<TreeNode*> st;
        st.push(root);
        int sum = 0;
        while (!st.empty()) {
            TreeNode *node = st.top();
            st.pop();
            if (node->left && !node->left->left && !node->left->right) {
                sum += node->left->val;
            }
            if (node->right) {
                st.push(node->right);
            }
            if (node->left) {
                st.push(node->left);
            }
        }
        return sum;
    }
};
```

## [222. 完全二叉树的节点个数](https://leetcode.cn/problems/count-complete-tree-nodes/)

+ 递归+后序遍历

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
    int getNodeSum(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        int leftNum = getNodeSum(root->left);
        int rightNum = getNodeSum(root->right);
        return leftNum + rightNum + 1;
    }
    int countNodes(TreeNode* root) {
        return getNodeSum(root);
    }
};
```

+ 迭代+层序遍历

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
    int countNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int cnt = 0;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode *node = que.front();
                que.pop();
                cnt++;
                if (node->left) {
                    que.push(node->left);
                }
                if (node->right) {
                    que.push(node->right);
                }
            }
        }
        return cnt;
    }
};
```

