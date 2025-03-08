/*
一个游戏里面对英雄进行分类，一共有 n种职业， m 种阵营。
小蓝每天玩一个英雄，这个英雄属于某一种职业，也属于某一种阵营。每个英雄属于某个职业的概率是 
1/n，属于某种阵营的概率是 1/m 。求小蓝玩遍了所有职业和阵营的期望天数。
*/
#include <iostream>
using namespace std;
const int maxn=1e3+10;
double a[maxn][maxn];
int n,m;
void solve()
{
   a[n][m]=0;
   for(int i=n;i>=0;i--)
   {
     for(int j=m;j>=0;j--)
     {
         if(i==n&&m==j)continue;
       a[i][j]=(a[i][j+1]*(i*(m-j))+a[i+1][j]*((n-i)*j)+a[i+1][j+1]*((n-i)*(m-j))+a[i][j]*(i*j)+n*m)/(n*m-i*j);
     }
   }
   printf("%.4lf",a[0][0]);
}
int main()
{
  cin>>n>>m;
  solve();
  return 0;
}
