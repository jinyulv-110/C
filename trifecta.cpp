/*
�� 1,2,��,9 �� 9 �����ֳ� 3 �飬�ֱ���� 3 ����λ������ʹ�� 3 ����λ������ 1:2:3 �ı������������������������ 3 ����λ����
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
