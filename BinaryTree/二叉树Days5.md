# 二叉树Days5

## [654. 最大二叉树](https://leetcode.cn/problems/maximum-binary-tree/)

+ 用数组 + 前序遍历

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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode *node = new TreeNode(0);
        if (nums.size() == 1) {
            node->val = nums[0];
            return node;
        }

        int maxValue = INT_MIN;
        int maxValueIndex = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > maxValue) {
                maxValue = nums[i];
                maxValueIndex = i;
            }
        }

        node->val = maxValue;
        if (maxValueIndex > 0) {
            vector<int> temp(nums.begin(), nums.begin() + maxValueIndex);
            node->left = constructMaximumBinaryTree(temp);
        }
        if (maxValueIndex < nums.size() - 1) {
            vector<int> temp(nums.begin() + maxValueIndex + 1, nums.end());
            node->right = constructMaximumBinaryTree(temp);
        }

        return node;
    }
};
```

+ 用下标 + 前序遍历

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
    TreeNode* traversal(vector<int> &nums, int left, int right) {
        if (left >= right) {
            return nullptr;
        }   

        int maxValueIndex = left;
        for (int i = left + 1; i < right; i++) {
            if (nums[i] > nums[maxValueIndex]) {
                maxValueIndex = i;
            }
        }

        TreeNode *node = new TreeNode(nums[maxValueIndex]);
        node->left = traversal(nums, left, maxValueIndex);
        node->right = traversal(nums, maxValueIndex + 1, right);
        return node;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return traversal(nums, 0, nums.size());
    }
};
```

## [617. 合并二叉树](https://leetcode.cn/problems/merge-two-binary-trees/)

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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr) {
            return root2;
        }
        if (root2 == nullptr) {
            return root1;
        }
        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
    }
};
```

## [700. 二叉搜索树中的搜索](https://leetcode.cn/problems/search-in-a-binary-search-tree/)

+ 第一版本：

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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root->val == val) {
            return root;
        }

        if (val > root->val) {
            if (root->right) {
                return searchBST(root->right, val);
            }
        }
        if (val < root->val) {
            if (root->left) {
                return searchBST(root->left, val);
            }
        }

        return nullptr;
    }
};
```

+ 第二版本

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
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr || root->val == val) {
            return root;
        }

        if (val < root->val) {
            return searchBST(root->left, val);
        }
        if (val > root->val) {
            return searchBST(root->right, val);
        }

        return nullptr;
    }
};
```

## [98. 验证二叉搜索树](https://leetcode.cn/problems/validate-binary-search-tree/)

+ 利用中序遍历形成有序数组进行判断

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
    vector<int> result;
    void traversal(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        traversal(root->left);
        result.push_back(root->val);
        traversal(root->right);
    }
    bool isValidBST(TreeNode* root) {
        traversal(root);
        for (int i = 0; i < result.size() - 1; i++) {
            if (result[i] >= result[i + 1]) {
                return false;
            }
        }
        return true;
    }
};
```

+ 利用上一个节点判断：

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
    TreeNode *pre = nullptr;
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        bool left = isValidBST(root->left);

        if (pre != nullptr && pre->val >= root->val) {
            return false;
        }
        pre = root;

        bool right = isValidBST(root->right);

        return left && right;
    }
};
```

