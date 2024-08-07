# 字符串Days1

## [344. 反转字符串](https://leetcode.cn/problems/reverse-string/)

+ 双指针

```c++
class Solution {
public:
    void reverse(vector<char> &s, int left, int right) {
        while (left < right) {
            swap(s[left], s[right]);
            left++;
            right--;
        }
    }

    void reverseString(vector<char>& s) {
        reverse(s, 0, s.size() - 1);
    }
};
```

## [541. 反转字符串 II](https://leetcode.cn/problems/reverse-string-ii/)

```c++
class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i +=(2 * k)) {
            if (i + k <= s.size()) {
                reverse(s.begin() + i, s.begin() + k + i);
            }
            else {
                reverse(s.begin() + i, s.end());
            }
        }
        return s;
    }
};
```

## [54. 替换数字](https://kamacoder.com/problempage.php?pid=1064)

```c++
#include <iostream>
#include <numeric>
using namespace std;

void replaceNumber(string &s)
{
  int countNumber = 0;
  for (int i = 0; i < s.size(); i++)
  {
    if (isdigit(s[i]))
    {
      countNumber++;
    }
  }
  int oldSize = s.size();
  int newSize = s.size() + countNumber * 5;
  s.resize(newSize);
  int left = oldSize - 1;
  int right = newSize - 1;
  while (left >= 0)
  {
    if (isdigit(s[left]))
    {
      s[right--] = 'r';
      s[right--] = 'e';
      s[right--] = 'b';
      s[right--] = 'm';
      s[right--] = 'u';
      s[right--] = 'n';
    }
    else
    {
      s[right--] = s[left];
    }
    left--;
  }
}

int main()
{
  string s;
  cin >> s;
  replaceNumber(s);
  cout << s << endl;
}
```

