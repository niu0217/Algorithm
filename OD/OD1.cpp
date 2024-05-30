// 题目链接：https://blog.csdn.net/m0_47384542/article/details/131467158
// 考点：滑动窗口
// 题目：滑动窗口最大值

#include <iostream>
#include <numeric>
#include <vector>
#include <string>
using namespace std;

int getMaxWindowsValue(vector<int> &nums, int windowsSize)
{
  if (nums.size() <= windowsSize)
  {
    return accumulate(nums.begin(), nums.end(), 0);
  }

  int maxWindowsValue = INT_MIN;
  int curValues = accumulate(nums.begin(), nums.begin() + windowsSize, 0);
  int i = 0;
  for (int j = windowsSize; j < nums.size(); j++)
  {
    curValues -= nums[i++];
    curValues += nums[j];
    if (curValues > maxWindowsValue)
    {
      maxWindowsValue = curValues;
    }
  }
  return maxWindowsValue;
}

int main()
{
  int m; // 一共多少个数字
  int n; // 滑动窗口大小

  cin >> m;
  vector<int> nums(m, 0);
  for (int i = 0; i < m; i++)
  {
    cin >> nums[i];
  }
  cin >> n;

  int result = getMaxWindowsValue(nums, n);
  cout << result << endl;
}