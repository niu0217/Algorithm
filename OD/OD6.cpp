// 题目链接：https://blog.csdn.net/m0_47384542/article/details/131884335
// 考点：滑动窗口
// 题目：满足条件的最长子串的长度II

#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int getLargestSubStr(const string &s, char ch)
{
  unordered_map<char, int> mapS;
  int len = s.size();
  int maxLen = 0;
  int start = 0;
  for (int i = 0; i < len; i++)
  {
    int curCh = s[i];
    if (curCh == ch)
    {
      mapS.clear();
      start = i + 1;
      continue;
    }
    mapS[curCh]++;
    if (mapS[curCh] == 3)
    {
      start++;
      mapS[curCh]--;
    }
    maxLen = max(maxLen, i - start + 1);
  }
  return maxLen;
}

int main()
{
  char ch;
  string s;
  cin >> ch >> s;
  cout << getLargestSubStr(s, ch) << endl;
}