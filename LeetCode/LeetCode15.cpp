/* ************************************************************************
> File Name:     LeetCode15.cpp
> Author:        niu0217
> Created Time:  Fri 14 Jun 2024 01:47:21 PM CST
> Description:   三数之和 双指针
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
  vector<vector<int>> threeSum(vector<int> &nums)
  {
    sort(nums.begin(), nums.end());

    vector<vector<int>> result;
    int len = nums.size();
    for (int i = 0; i < len; i++)
    {
      if (nums[i] > 0)
      {
        break;
      }
      if (i > 0 && nums[i - 1] == nums[i])
      {
        continue;
      }
      int left = i + 1;
      int right = len - 1;
      while (left < right)
      {
        if (nums[i] + nums[left] + nums[right] > 0)
        {
          right--;
        }
        else if (nums[i] + nums[left] + nums[right] < 0)
        {
          left++;
        }
        else
        {
          result.push_back({nums[i], nums[left], nums[right]});
          while (left < right && nums[left] == nums[left + 1])
          {
            left++;
          }
          while (left < right && nums[right] == nums[right - 1])
          {
            right--;
          }
          left++;
          right--;
        }
      }
    }
    return result;
  }
};

int main()
{
}