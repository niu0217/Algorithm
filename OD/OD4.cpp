// 题目链接：https://blog.csdn.net/m0_47384542/article/details/131876900
// 考点：滑动窗口
// 题目：最左侧冗余覆盖子串

#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int getLeftCoverString(const string &s1, const string &s2, int k)
{
  int len1 = s1.size();
  int len2 = s2.size();
  vector<char> countS1(26, 0);
  vector<char> countWindows(26, 0);

  for (char ch : s1)
  {
    countS1[ch - 'a']++;
  }

  int start = 0;
  int end = 0;
  while (end < len2)
  {
    countWindows[s2[end] - 'a']++;
    if (end - start + 1 >= len1 + k)
    {
      bool flag = true;
      for (int i = 0; i < 26; i++)
      {
        if (countS1[i] > countWindows[i])
        {
          flag = false;
          break;
        }
      }
      if (flag)
      {
        return start;
      }
      countWindows[s2[start] - 'a']--;
      start++;
    }
    end++;
  }
  return -1;
}

int getLeftCoverString_map(const string &s1, const string &s2, int k)
{
  int len1 = s1.size();
  int len2 = s2.size();
  unordered_map<char, int> mapS1;
  unordered_map<char, int> mapWindows;
  for (char ch : s1)
  {
    mapS1[ch]++;
  }

  int start = 0;
  int end = 0;
  while (end < len2)
  {
    mapWindows[s2[end]]++;
    // 滑动窗口大小为len + k
    if (end - start + 1 >= len1 + k)
    {
      bool flag = true;
      for (int i = 0; i < len1; i++)
      {
        if (mapS1[s1[i]] > mapWindows[s1[i]])
        {
          flag = false;
          break;
        }
      }
      if (flag)
      {
        return start;
      }
      mapWindows[s2[start]]--;
      if (mapWindows[s2[start]] == 0)
      {
        mapWindows.erase(s2[start]);
      }
      start++;
    }
    end++;
  }
  return -1;
}

int main()
{
  string s1;
  string s2;
  int k;
  cin >> s1 >> s2;
  cin >> k;

  cout << getLeftCoverString_map(s1, s2, k) << endl;
}