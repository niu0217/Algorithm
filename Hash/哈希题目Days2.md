# 哈希题目Days2

## [454. 四数相加 II](https://leetcode.cn/problems/4sum-ii/)

```c++
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> umap;
        for (int a : A) {
            for (int b : B) {
                umap[a + b]++;
            }
        }
        int count = 0;
        for (int c : C) {
            for (int d : D) {
                if (umap.find(0 - (c + d)) != umap.end()) {
                    count += umap[0 - (c + d)];
                }
            }
        }
        return count;
    }
};
```

## [383. 赎金信](https://leetcode.cn/problems/ransom-note/)

```c++
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int records[26] = {0};
        for (int i = 0; i < magazine.size(); i++) {
            records[magazine[i] - 'a']++;
        }
        for (int i = 0; i < ransomNote.size(); i++) {
            records[ransomNote[i] - 'a']--;
            if (records[ransomNote[i] - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};
```

## [15. 三数之和](https://leetcode.cn/problems/3sum/)

+ 双指针法：

```c++
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int size = nums.size();
        for (int i = 0; i < size - 2; i++) {
            if (nums[i] > 0) {
                return result;
            }
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int left = i + 1;
            int right = size - 1;
            while (left < right) {
               if (nums[i] + nums[left] + nums[right] > 0) {
                right--;
               }
               else if(nums[i] + nums[left] + nums[right] < 0) {
                left++;
               }
               else {
                result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                while (left < right && nums[right] == nums[right - 1]) {
                    right--;
                }
                while (left < right && nums[left] == nums[left + 1]) {
                    left++;
                }
                left++;
                right--;
               }
            }
        }
        return result;
    }
};
```

## [18. 四数之和](https://leetcode.cn/problems/4sum/)

+ 双指针：

```c++
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            if (nums[i] > target && nums[i] >= 0) {
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < size; j++) {
                if (nums[i] + nums[j] > target && nums[i] + nums[j] >= 0) {
                    break;
                }
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                int left = j + 1;
                int right = size - 1;
                while (left < right) {
                    if ((long)nums[i] + nums[j] + nums[left] + nums[right] > target) {
                        right--;
                    }
                    else if ((long)nums[i] + nums[j] + nums[left] + nums[right] < target) {
                        left++;
                    }
                    else {
                        result.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[right] == nums[right - 1]) {
                            right--;
                        }
                        while (left < right && nums[left] == nums[left + 1]) {
                            left++;
                        }
                        left++;
                        right--;
                    }
                }
            } 
        }
        return result;
    }
};
```

注意点：

+ `(long)nums[i] + nums[j] + nums[left] + nums[right] > target`这里的long必须加，不然会溢出。



