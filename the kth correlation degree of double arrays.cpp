/*
给定两个长度相同的正整数数组 A 和 B。定义一个数组 C，其中每一个元素 C[i] 是 A[x]+B[y] 的形式,
其中 0≤x,y<n。现在，你的任务是找到 C 中第 k 小的元素。
*/
#include <stdio.h>
typedef long long ll;
#define N 2000009
ll a[N],c[N],b[N];
void solve()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
      scanf("%lld",&a[i]);   //数组A
    for(int i=1;i<=n;i++)
       scanf("%lld",&b[i]);   //数组B
     int k;                   //目标值
     scanf("%d",&k); 
     for(int i=1;i<=n;i++)
         for(int j=1;j<=n;j++)
             c[a[i]+b[j]]++;       //统计a[i]+b[j]出现次数到数组c
       
       for(ll i=1;i<=2000099;i++)      //桶排序
       {
           if(c[i]>=k)      //当>=k,说明当前i是第k小
           {
               printf("%lld\n",i);
               break;
           }
           k-=c[i];         //若<k,将k更新为剩余需要找的个数
       }
}

int main()
{
    solve();
    return 0; 
}
