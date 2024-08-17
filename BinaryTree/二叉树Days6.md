# 二叉树Days6

## [530. 二叉搜索树的最小绝对差](https://leetcode.cn/problems/minimum-absolute-difference-in-bst/)

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
    int result = INT_MAX;
    void traversal(TreeNode * root) {
        if (root == nullptr) {
            return;
        }
        traversal(root->left);
        if (pre != nullptr) {
            int gap = abs(root->val - pre->val);
            result = min(gap, result);
        }
        pre = root;
        traversal(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        traversal(root);
        return result;
    }
};
```

## [501. 二叉搜索树中的众数](https://leetcode.cn/problems/find-mode-in-binary-search-tree/)

+ 二叉搜索树的做法：

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
    int maxCount = 0;
    int count = 0;
    TreeNode *pre = nullptr;
    vector<int> result;
    void searchBST(TreeNode *cur) {
        if (cur == nullptr) {
            return;
        }

        searchBST(cur->left);

        if (pre == nullptr) {
            count = 1;
        }
        else if (pre->val == cur->val) {
            count++;
        }
        else {
            count = 1;
        }
        pre = cur;

        if (count == maxCount) {
            result.push_back(cur->val);
        }
        if (count > maxCount) {
            maxCount = count;
            result.clear();
            result.push_back(cur->val);
        }

        searchBST(cur->right);
    }

public:
    vector<int> findMode(TreeNode* root) {
        searchBST(root);
        return result;
    }
};
```

+ 普通二叉树的做法：

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
    void traversal(TreeNode *cur, unordered_map<int, int> &treeMap) {
        if (cur == nullptr) {
            return;
        }
        treeMap[cur->val]++;
        traversal(cur->left, treeMap);
        traversal(cur->right, treeMap);
    }
    static bool compare(pair<int, int> &lhs, pair<int, int> &rhs) {
        return lhs.second > rhs.second;
    }
public:
    vector<int> findMode(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        unordered_map<int, int> treeMap;
        traversal(root, treeMap);
        vector<pair<int, int>> treeVec(treeMap.begin(), treeMap.end());
        sort(treeVec.begin(), treeVec.end(), compare);

        vector<int> result;
        result.push_back(treeVec[0].first);
        for (int i = 1; i < treeVec.size(); i++) {
            if (treeVec[0].second == treeVec[i].second) {
                result.push_back(treeVec[i].first);
            }
            else {
                break;
            }
        }
        return result;
    }
};
```

## [236. 二叉树的最近公共祖先](https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/)

+ 采用后序遍历

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return nullptr;
        }
        if (root == p || root == q) {
            return root;
        }

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        if (left !=nullptr && right != nullptr) {
            return root;
        }
        if (left == nullptr && right != nullptr) {
            return right;
        }
        if (left != nullptr && right == nullptr) {
            return left;
        }
        if (!left && !right) {
            return nullptr;
        }
        return nullptr;
    }
};
```

