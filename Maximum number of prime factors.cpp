/*
给定一个正整数 N,请你在 2 到 N 之间找到拥有不同质因子个数最多的整数，并求出该整数的不同质因子的个数。
*/

#include <stdio.h>
#include <stdlib.h>
long long prime(long long p)
{
  for(int i=2;i*i<=p;i++)
  {
    if(p%i==0)
      return 0;
  }
  return 1;
}
int main(int argc, char *argv[])
{
  long long i,n=0;
  long long arr[20]={1};
  for(i=2;;i++)
  {
    if(prime(i))
    {
      arr[++n]=i;
      arr[n]*=arr[n-1];
    }
    if(arr[n]>=1000000000000000000 || arr[n]<0)
      break;
  }
  long long T,t;
  scanf("%lld",&T);
  while(T--)
  {
    scanf("%lld",&t);
    for(i=1;i<n;i++)
    {
      if(t<arr[i+1] || arr[i+1]<0)
      {
        printf("%lld\n",i);
        break;
      }
    }
  }
  return 0;
}
