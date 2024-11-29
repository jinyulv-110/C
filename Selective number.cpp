/*已知 n个整数 x1,x2,... ,xn,以及一个整数 
k（k＜n）。从 
n 个整数中任选 
k 个整数相加，可分别得到一系列的和。例如当 
n=4，
k＝3，
4 个整数分别为 
3，7，12，19 时，可得全部的组合与它们的和为： 
3＋7＋12=22  3＋7＋19＝29  7＋12＋19＝38  3＋12＋19＝34。 
现在，要求你计算出和为素数共有多少种。 例如上例，只有一种的和为素数：
3＋7＋19＝29。*/
#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int n,k,sum=0;
int a[101];
int pd(int x){
    for(int i=2;i<sqrt(x);i++){
        if(x%i==0){
            return 1;
        }
    }
    return 0;
}
void dfs(int p,int s,int st){
    if(p==k){
        if(pd(s)!=1){
            sum++;
        }
        return;
    }
    for(int i=st;i<=n;i++){
            p++;
            dfs(p,s+a[i],i+1);
            p--;
    }
    return;
}
int main(int argc, char *argv[])
{
  scanf("%d%d",&n,&k);
  for(int i=1;i<=n;i++){
      scanf("%d",&a[i]);
  }
  dfs(0,0,1);
  printf("%d",sum);
  return 0;
}
