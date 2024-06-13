/* ************************************************************************
> File Name:     LeetCode128.cpp
> Author:        niu0217
> Created Time:  Thu 13 Jun 2024 03:59:41 PM CST
> Description:   最长连续序列 哈希
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution
{
public:
  int longestConsecutive(vector<int> &nums)
  {
    // 用set对nums去重
    unordered_set<int> numberSet;
    for (int num : nums)
    {
      numberSet.insert(num);
    }
    int maxLen = 0;
    for (int num : nums)
    {
      if (!numberSet.count(num - 1)) // 没有找到比num小一的数
      {
        int curNum = num;
        int curLen = 1;
        while (numberSet.count(curNum + 1))
        {
          curLen += 1;
          curNum += 1;
        }
        maxLen = max(curLen, maxLen);
      }
    }
    return maxLen;
  }
};

int main()
{
}