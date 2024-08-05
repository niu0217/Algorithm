# 哈希题目Days1

## [242. 有效的字母异位词](https://leetcode.cn/problems/valid-anagram/)

```c++
class Solution {
public:
    bool isAnagram(string s, string t) {
        int records[26] = {0};
        int lenS = s.size();
        int lenT = t.size();
        for (int i = 0; i < lenS; i++)
        {
            records[s[i] - 'a']++;
        }
        for (int i = 0; i < lenT; i++)
        {
            records[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++)
        {
            if (records[i] != 0)
            {
                return false;
            }
        }
        return true;
    }
};
```

## [349. 两个数组的交集](https://leetcode.cn/problems/intersection-of-two-arrays/)

```c++
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> uset1(nums1.begin(), nums1.end());
        unordered_set<int> result;
        for (int i = 0; i < nums2.size(); i++) {
            if (uset1.find(nums2[i]) != uset1.end()) {
                result.insert(nums2[i]);
            }
        }
        return vector<int>(result.begin(), result.end());
    }
};
```

## [202. 快乐数](https://leetcode.cn/problems/happy-number/)

```c++
class Solution {
public:
    int getSum(int n) {
        int sum = 0;
        while (n != 0) {
            int num = n % 10;
            sum += num * num;
            n = n / 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> res;
        while (1) {
            int sum = getSum(n);
            if (sum == 1) {
                return true;
            }
            if (res.find(sum) != res.end()) {
                return false;
            }
            res.insert(sum);
            n = sum;
        }
        return false;
    }
};
```

## [1. 两数之和](https://leetcode.cn/problems/two-sum/)

```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int, int> umap;
       int len = nums.size();
       for (int i = 0; i < len; i++) {
        auto iter = umap.find(target - nums[i]);
        if (iter != umap.end()) {
            return {i, iter->second};
        }
        umap[nums[i]] = i;
       }
       return {};
    }
};
```

