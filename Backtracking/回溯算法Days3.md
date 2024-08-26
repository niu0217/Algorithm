# 回溯算法Days3

## [93. 复原 IP 地址](https://leetcode.cn/problems/restore-ip-addresses/)

思路：切割问题，

```c++
class Solution {
public:
    bool isValid(const string &s, int start, int end) {
        if (start > end) {
            return false;
        }
        if (s[start] == '0' && start != end) {
            return false;
        }
        int num = 0;
        for (int i = start; i <= end; i++) {
            if (s[i] < '0' || s[i] > '9') {
                return false;
            }
            num = num * 10 + (s[i] - '0');
            if (num > 255) {
                return false;
            }
        }
        return true;
    }
public:
    vector<string> result;
    void backtracking(string &s, int pointNum, int startIndex) {
        if (pointNum == 3) {
            if (isValid(s, startIndex, s.size() - 1)) {
                result.push_back(s);
            }
            return;
        }
        for (int i = startIndex; i < s.size(); i++) {
            if (isValid(s, startIndex, i)) {
                s.insert(s.begin() + i + 1, '.');
                pointNum++;
                backtracking(s, pointNum, i + 2);
                pointNum--;
                s.erase(s.begin() + i + 1);
            }
            else {
                break;
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        int size = s.size();
        if (size < 4 || s.size() > 12) {
            return result;
        }
        backtracking(s, 0, 0);
        return result;
    }
};
```

![93.复原IP地址](回溯算法Days3.assets/20201123203735933-20230310132314109.png) 

## [78. 子集](https://leetcode.cn/problems/subsets/)

```c++
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int> &nums, int startIndex) {
        result.push_back(path);
        for (int i = startIndex; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.size() == 0) {
            return {};
        }
        backtracking(nums, 0);
        return result;
    }
};
```

## [90. 子集 II](https://leetcode.cn/problems/subsets-ii/)

```c++
class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int> &nums, int startIndex, vector<bool> &used) {
        result.push_back(path);
        for (int i = startIndex; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
                continue;
            }
            path.push_back(nums[i]);
            used[i] = true;
            backtracking(nums, i + 1, used);
            used[i] = false;
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtracking(nums, 0, used);
        return result;
    }
};
```

