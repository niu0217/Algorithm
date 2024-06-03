// 题目链接：https://blog.csdn.net/m0_47384542/article/details/131884157
// 考点：滑动窗口
// 题目：满足条件的最长子串的长度I

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int getLargestSubStr(const string &s)
{
  int len = s.size();
  int maxLen = 0;
  for (int i = 0; i < len; i++)
  {
    // 当前字符是一个字母
    if (isalpha(s[i]))
    {
      int curLen = 1;
      int j = i - 1;
      // 统计从当前字符到第一个字符
      while (j >= 0 && isdigit(s[j]))
      {
        ++curLen;
        --j;
      }
      // 统计从当前字符到最后一个字符
      j = i + 1;
      while (j < len && isdigit(s[j]))
      {
        ++curLen;
        ++j;
      }
      maxLen = max(maxLen, curLen);
    }
  }
  if (maxLen > 1)
  {
    return maxLen;
  }
  return -1;
}

int main()
{
  string s;
  cin >> s;
  cout << getLargestSubStr(s) << endl;
}