/* ************************************************************************
> File Name:     LeetCode1.cpp
> Author:        niu0217
> Created Time:  Tue 11 Jun 2024 01:18:26 PM CST
> Description:   两数之和 哈希
 ************************************************************************/

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

class Solution
{
public:
  vector<int> twoSum(vector<int> &nums, int target)
  {
    unordered_map<int, int> numsMap;
    int len = nums.size();
    for (int i = 0; i < len; i++)
    {
      auto iter = numsMap.find(target - nums[i]);
      if (iter != numsMap.end())
      {
        return {iter->second, i};
      }
      numsMap[nums[i]] = i;
    }
    return {};
  }
};

int main()
{
  Solution so;
  vector<int> nums = {3, 2, 4};
  int target = 6;
  vector<int> result = so.twoSum(nums, target);
  for (int num : result)
  {
    cout << num << " ";
  }
  cout << endl;
}