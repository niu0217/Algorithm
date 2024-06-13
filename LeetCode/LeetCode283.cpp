/* ************************************************************************
> File Name:     LeetCode283.cpp
> Author:        niu0217
> Created Time:  Thu 13 Jun 2024 04:18:09 PM CST
> Description:   移动零 双指针
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
  void moveZeroes(vector<int> &nums)
  {
    // slow 需要修改的位置
    // fast 下一个不为0的位置
    int slow = 0;
    int len = nums.size();
    for (int fast = 0; fast < len; fast++)
    {
      if (nums[fast] != 0)
      {
        swap(nums[fast], nums[slow]);
        slow++;
      }
    }
  }
};

int main()
{
}