# 二叉树Days4

## 今日精华

**什么时候递归函数需要返回值？**

+ 如果需要搜索整棵二叉树且不用处理递归返回值，递归函数就不要返回值。

+ 如果需要搜索整棵二叉树且需要处理递归返回值，递归函数就需要返回值。
+ 如果要搜索其中一条符合条件的路径，那么递归一定需要返回值，因为遇到符合条件的路径了就要及时返回。



## [513. 找树左下角的值](https://leetcode.cn/problems/find-bottom-left-tree-value/)

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
    int findBottomLeftValue(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        queue<TreeNode*> que;
        que.push(root);
        int result = 0;
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode *node = que.front();
                que.pop();
                if (i == 0) {
                    result = node->val;
                }
                if (node->left) {
                    que.push(node->left);
                }
                if (node->right) {
                    que.push(node->right);
                }
            }
        }
        return result;
    }
};
```

## [112. 路径总和](https://leetcode.cn/problems/path-sum/)

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
    bool backtracking(TreeNode *root, int sum) {
        if (sum == 0 && root->left == nullptr && root->right == nullptr) {
            return true;
        }
        if (!root->left && !root->right) {
            return false;
        }
        if (root->left) {
            if (backtracking(root->left, sum - root->left->val)) {
                return true;
            }
        }
        if (root->right) {
            if (backtracking(root->right, sum - root->right->val)) {
                return true;
            }
        }
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return false;
        }
        return backtracking(root, targetSum - root->val);
    }
};
```

## [113. 路径总和 II](https://leetcode.cn/problems/path-sum-ii/)

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
    vector<vector<int>> result;
    vector<int> path;
    void traversal(TreeNode *cur, int sum) {
        if (sum == 0 && !cur->left && !cur->right) {
            result.push_back(path);
            return;
        }
        if (!cur->left && !cur->right) {
            return;
        }
        if (cur->left) {
            path.push_back(cur->left->val);
            traversal(cur->left, sum - cur->left->val);
            path.pop_back();
        }
        if (cur->right) {
            path.push_back(cur->right->val);
            traversal(cur->right, sum - cur->right->val);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return {};
        }
        result.clear();
        path.clear();
        path.push_back(root->val);
        traversal(root, targetSum - root->val);
        return result;
    }
};
```

## [106. 从中序与后序遍历序列构造二叉树](https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/)

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
    TreeNode* traversal(vector<int> &inorder, vector<int> &postorder) {
        if (postorder.size() == 0) {
            return nullptr;
        }

        int rootValue = postorder[postorder.size() - 1];
        TreeNode *root = new TreeNode(rootValue);

        int index = 0;
        for (int i = 0; i < inorder.size(); i++) {
            if (inorder[i] == rootValue) {
                index = i;
                break;
            }
        }

        vector<int> leftInorder(inorder.begin(), inorder.begin() + index);
        vector<int> rightInorder(inorder.begin() + index + 1, inorder.end());

        postorder.resize(postorder.size() - 1);

        vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
        vector<int> rightPostorder(postorder.begin() + leftInorder.size(), postorder.end());

        root->left = traversal(leftInorder, leftPostorder);
        root->right = traversal(rightInorder, rightPostorder);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0 || postorder.size() == 0) {
            return nullptr;
        }
        return traversal(inorder, postorder);
    }
};
```

## [105. 从前序与中序遍历序列构造二叉树](https://leetcode.cn/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)

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
    TreeNode* traversal(vector<int> &preorder, int preBegin, int preEnd,
                        vector<int> &inorder, int inoBegin, int inoEnd) {
        if (preBegin == preEnd) {
            return nullptr;
        }

        int rootValue = preorder[preBegin];
        TreeNode *root = new TreeNode(rootValue);

        if (preEnd - preBegin == 1) {
            return root;
        }

        int index;
        for (index = 0; index < inorder.size(); index++) {
            if (inorder[index] == rootValue) {
                break;
            }
        }

        int leftPreBegin = preBegin + 1;
        int leftPreEnd = preBegin + 1 + index - inoBegin;
        int leftInoBegin = inoBegin;
        int leftInoEnd = index;

        int rightPreBegin = leftPreEnd;
        int rightPreEnd = preEnd;
        int rightInoBegin = index + 1;
        int rightInoEnd = inoEnd;

        root->left = traversal(preorder, leftPreBegin, leftPreEnd,
                               inorder, leftInoBegin, leftInoEnd);
        root->right = traversal(preorder, rightPreBegin, rightPreEnd,
                                inorder, rightInoBegin, rightInoEnd);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0 || inorder.size() == 0) {
            return nullptr;
        }
        // 左闭右开原则
        return traversal(preorder, 0, preorder.size(),
                         inorder, 0, inorder.size());
    }
};
```

