/*给定两个正整数 n,num，小蓝需要求出来 n 分解质因数之后的质因子的和是多少，
然后设这个和为 x。例如 
8=2×2×2，则 x=6。
最终求出 x 和 n 的最小公倍数后与 
num 相比较，看是否一致。也就是说如果
lcm(x,n)=num，则输出 YES，否则输出 NO。*/
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
