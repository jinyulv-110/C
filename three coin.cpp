/*小蓝是个热衷于存钱的小伙。他有一个存钱罐，里面存有 
N
N 枚硬币，硬币的面值分别为 
A
1
,
A
2
,
?
,
A
N
A 
1
?
 ,A 
2
?
 ,?,A 
N
?
 。

这天，小蓝决定带着这 
N
N 枚硬币去往他最喜爱的玩具店进行消费。只不过，妈妈规定，小蓝最多只能使用这 
N
N 枚硬币中的其中 
3
3 枚。

对此，请你帮小蓝算算，在使用不超过 
3
3 枚硬币的情况下，小蓝能够支付多少种不同的金额呢？

注意，
0
0 元也算一种金额。*/
#include<iostream>
#include<cstdio>
using namespace std;
int n,ans=1,s;
int vi[4][3005];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i+=1){
        int x; scanf("%d",&x);
        for(int j=(s+=x);j>=x;j-=1){
      if (vi[1][j-x]) vi[2][j] = 1;
      if (vi[2][j-x]) vi[3][j] = 1; 
        }
        vi[1][x]=1;
    }
    for(int i=1;i<=s;i+=1){
        ans+=(vi[1][i]|vi[2][i]|vi[3][i]);
    }
    printf("%d\n",ans);
    return 0;
}
