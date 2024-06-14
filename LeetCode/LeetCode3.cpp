/* ************************************************************************
> File Name:     LeetCode3.cpp
> Author:        niu0217
> Created Time:  Fri 14 Jun 2024 02:12:20 PM CST
> Description:   无重复字符的最长子串 滑动窗口
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
  int lengthOfLongestSubstring(string s)
  {
    unordered_map<char, int> umap;
    int maxLen = 0;
    int len = s.size();
    int left = 0;
    for (int i = 0; i < len; i++)
    {
      umap[s[i]]++;
      while (umap[s[i]] > 1)
      {
        umap[s[left]]--;
        if (umap[s[left]] == 0)
        {
          umap.erase(s[left]);
        }
        left++;
      }
      int curLen = i - left + 1;
      maxLen = max(maxLen, curLen);
    }
    return maxLen;
  }
};

int main()
{
}