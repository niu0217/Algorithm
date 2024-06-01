// 题目链接：https://blog.csdn.net/m0_47384542/article/details/131707537
// 考点：滑动窗口
// 题目：高矮个子排队

#include <iostream>
#include <vector>
using namespace std;

/// 根据下标的奇偶性和元素大小交换位置并打印输出修改后的数组
void printSortByHigh(vector<int> &nums)
{
  int len = nums.size();
  for (int i = 0; i < len; i++)
  {
    if (i % 2 == 0 && i < len - 1 && nums[i] < nums[i + 1])
    {
      swap(nums[i], nums[i + 1]);
    }
    if (i % 2 == 1 && i < len - 1 && nums[i] > nums[i + 1])
    {
      swap(nums[i], nums[i + 1]);
    }
    if (i != 0)
    {
      cout << " ";
    }
    cout << nums[i];
  }
  cout << endl;
}

int main()
{
  vector<int> nums;
  int number;
  char ch;
  while (cin >> number)
  {
    nums.push_back(number);
    ch = getchar();
    if (ch == '\n')
    {
      break;
    }
    if (ch != ' ') // 出错处理
    {
      cout << endl;
      return 0;
    }
  }

  printSortByHigh(nums);
}