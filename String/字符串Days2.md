# 字符串Days2

## [151. 反转字符串中的单词](https://leetcode.cn/problems/reverse-words-in-a-string/)

```c++
class Solution {
public:
    void removeSpaces(string &s) {
        int slow = 0;  // 需要修改的位置
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                if (slow != 0) {
                    s[slow] = ' ';
                    slow++;
                }
                while (i < s.size() && s[i] != ' ') {
                    s[slow] = s[i];
                    slow++;
                    i++;
                }
            }
        }
        return s.resize(slow);
    }
public:
    string reverseWords(string s) {
        removeSpaces(s);
        reverse(s.begin(), s.end());
        int start = 0;
        for (int i = 0; i <= s.size(); i++) {
            if (s[i] == ' ' || i == s.size()) {
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }
        return s;
    }
};
```

## [55. 右旋字符串](https://kamacoder.com/problempage.php?pid=1065)

```c++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    int n;
    cin >> n;
    cin >> s;
    reverse(s.begin(), s.end());
    reverse(s.begin(), s.begin() + n);
    reverse(s.begin() + n, s.end());
    cout << s << endl;
}
```

## [28. 找出字符串中第一个匹配项的下标](https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/)

```c++
class Solution {
public:
    void getNext(string &s, vector<int> &next) {
        int j = 0;
        next[0] = 0;
        for (int i = 1; i < s.size(); i++) {
            while (j > 0 && s[i] != s[j]) {
                j = next[j - 1];
            }
            if (s[i] == s[j]) {
                j++;
            }
            next[i] = j;
        }
    }
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) {
            return 0;
        }
        vector<int> next(needle.size(), 0);
        getNext(needle, next);
        int j = 0;
        for (int i = 0; i < haystack.size(); i++) {
            while (j > 0 && haystack[i] != needle[j]) {
                j = next[j - 1];
            }
            if (haystack[i] == needle[j]) {
                j++;
            }
            if (j == needle.size()) {
                return i - needle.size() + 1;
            }
        }
        return -1;
    }
};
```

