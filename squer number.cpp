/*
若一个正整数 x 可以表示为 i2且 i>0，则称 x 为平方数。
现在有T 次询问，每次询问给出一个正整数 n，请你回答有多少个平方数小于等于 n。
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(int argc, char *argv[])
{
  // 请在此输入您的代码
  int T;
  long long n;
  scanf("%d",&T);
  for(int i=1;i<=T;i++)
  {
    scanf("%lld",&n);
    int sum=(int)sqrt(n);
    printf("%d\n",sum);
  }
return 0;
}
