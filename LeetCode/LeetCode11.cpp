/* ************************************************************************
> File Name:     LeetCode11.cpp
> Author:        niu0217
> Created Time:  Thu 13 Jun 2024 04:38:45 PM CST
> Description:   盛最多水的容器 双指针
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
  int maxArea(vector<int> &height)
  {
    int res = 0;
    int i = 0;
    int j = height.size() - 1;
    while (i < j)
    {
      int area = (j - i) * min(height[i], height[j]);
      res = max(res, area);
      if (height[i] < height[j])
      {
        i++;
      }
      else
      {
        j--;
      }
    }
    return res;
  }
};

int main()
{
}