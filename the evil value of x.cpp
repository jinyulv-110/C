/*С�Ƕ���һ���� x �����ֵΪ������ x ����С������ w �ĳ˻���
���ڸ�����һ������ n������Ҫ��� n �����ֵ��
*/
#include <iostream>
using namespace std;
bool iszhi(long long a){
  for(int i=3;i*i<=a;i=i+2){
    if(a%i==0) return 0;
  }
  return 1;
}
int main()
{
  long long n,w;
  cin>>n>>w;
  n++;
  if(n%2==0) n++;
  if(n==3) cout<<2*w;
  else{
    while(!iszhi(n)) n+=2;
    cout<<(long long)(n*w);
  }
  return 0;
}
