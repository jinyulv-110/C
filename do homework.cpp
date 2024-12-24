/*�������������� n,num��С����Ҫ����� n �ֽ�������֮��������ӵĺ��Ƕ��٣�
Ȼ���������Ϊ x������ 
8=2��2��2���� x=6��
������� x �� n ����С���������� 
num ��Ƚϣ����Ƿ�һ�¡�Ҳ����˵���
lcm(x,n)=num������� YES��������� NO��*/
#include <stdio.h>
#include <stdlib.h>
int Sum(int n)
{
  int sum=0;
  for(int i=2;i*i<=n;i++)
  {
    while(n%i==0)
    {
      sum+=i;
      n/=i;
    }
  }
  if(n>1)
    sum+=n;
  return sum;
}
int gcd(int a,int b)
{
  while(a%b)
  {
    int t=a%b;
    a=b;
    b=t;
  }
  return b;
}
int lcm(int x,int n)
{
  return (x*n)/gcd(x,n);
}
int main(int argc, char *argv[])
{
  int T,n,num;
  scanf("%d",&T);
  for(int i=0;i<T;i++)
  {
    scanf("%d %d",&n,&num);
    int x=Sum(n);
    if(lcm(x,n)==num)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
