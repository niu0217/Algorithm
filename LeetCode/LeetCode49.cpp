/* ************************************************************************
> File Name:     LeetCode49.cpp
> Author:        niu0217
> Created Time:  Tue 11 Jun 2024 01:45:37 PM CST
> Description:   字母异位词分组 哈希
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

class Solution
{
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs)
  {
    unordered_map<string, vector<string>> smap;
    vector<vector<string>> result;
    for (string s : strs)
    {
      string sortedS = s;
      sort(sortedS.begin(), sortedS.end());
      smap[sortedS].push_back(s);
    }
    for (auto part : smap)
    {
      result.push_back(part.second);
    }
    return result;
  }
};

int main()
{
}