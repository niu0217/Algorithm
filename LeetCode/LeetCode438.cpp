/* ************************************************************************
> File Name:     LeetCode438.cpp
> Author:        niu0217
> Created Time:  Fri 14 Jun 2024 02:33:24 PM CST
> Description:   找到字符串中所有字母异位词 滑动窗口
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
  vector<int> findAnagrams(string s, string p)
  {
    int sLen = s.size();
    int pLen = p.size();
    if (pLen > sLen)
    {
      return {};
    }
    vector<int> result;
    vector<int> sMap(26, 0);
    vector<int> pMap(26, 0);
    for (int i = 0; i < pLen; i++)
    {
      sMap[s[i] - 'a']++;
      pMap[p[i] - 'a']++;
    }
    if (sMap == pMap)
    {
      result.push_back(0);
    }
    for (int slow = 0; slow < sLen - pLen; slow++)
    {
      sMap[s[slow] - 'a']--;
      int fast = slow + pLen;
      sMap[s[fast] - 'a']++;
      if (sMap == pMap)
      {
        result.push_back(slow + 1);
      }
    }
    return result;
  }
};

int main()
{
}