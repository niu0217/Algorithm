// 题目链接：https://blog.csdn.net/m0_47384542/article/details/131706637
// 考点：滑动窗口
// 题目：用连续自然数之和来表达整数

#include <iostream>
#include <vector>
using namespace std;

/*
 根据数学公式从m连续加到n，结果是 t = (m+n)(n-m+1)/2
 如果从m开始加i个数，即从m加到m+i-1，得到 t = (2*m+i-1)*i/2
 因此推导出 m = ((2*t/i)-i+1)/2
 要想有解，则(2*t/i)和((2*t/i)-i+1)/2都必须可以整除
*/
void printExpressions(int t)
{
  int cnt = 1;
  cout << t << "=" << t << endl;
  for (int i = 2; i < t; i++)
  {
    if ((2 * t) % i == 0 &&
        (((2 * t) / i) - i + 1) % 2 == 0)
    {
      int m = (((2 * t) / i) - i + 1) / 2;
      if (m <= 0)
      {
        break;
      }
      cnt++;
      cout << t << "=";
      for (int j = 0; j < i; j++)
      {
        cout << m + j;
        if (j != i - 1)
        {
          cout << "+";
        }
      }
      cout << endl;
    }
  }
  cout << "Result:" << cnt << endl;
}

int main()
{
  int t;
  cin >> t;

  printExpressions(t);
}