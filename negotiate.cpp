/*
在很久很久以前，有 n 个部落居住在平原上，依次编号为 1 到 
n。 第 i 个部落的人数为 ti。  
有一年发生了灾荒。年轻的政治家小蓝想要说服所有部落一同应对灾荒，他能通过谈判来说服部落进行联合。
每次谈判，小蓝只能邀请两个部落参加，花费的金币数量为两个部落的人数之和，
谈判的效果是两个部落联合成一个部落（人数为原来两个部落的人数之和）。
*/

#include<bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{
  int n;
    int a[1005];
    int sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-i; j++) {
            sum += a[i];
        }
    }
    cout << sum - a[0];
  // 请在此输入您的代码
  return 0;
}
