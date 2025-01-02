/*有 N 个苹果需要分给 M 个人，
要让每个人得到的苹果数 相等 ，并且尽可能最大化这个数字。

求：最终每个人得到多少个苹果？还剩多少个苹果？*/
#include <iostream>
using namespace std;
int main()
{
  int t;
  cin >> t;
  while(t > 0) {
    int m, n;
    cin >> m >> n;
    cout << (m-m%n)/n << ' ' << m%n << endl;
    t--;
  }
  return 0;
}
