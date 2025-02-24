/*
将 1,2,…,9 共 9 个数分成 3 组，分别组成 3 个三位数，且使这 3 个三位数构成 1:2:3 的比例，试求出所有满足条件的 3 个三位数。
*/
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int mp[10]={1,2,3,4,5,6,7,8,9};
int main()
{
  do{
    int a=mp[0]*100+mp[1]*10+mp[2];
    int b=mp[3]*100+mp[4]*10+mp[5];
    int c=mp[6]*100+mp[7]*10+mp[8];
    if(a*3==c&&a*2==b)
    {
      cout<<a<<" "<<b<<" "<<c<<endl;
    }
  }while(next_permutation(mp,mp+9));
  return 0;
}
