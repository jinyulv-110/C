/*С���Ǹ������ڴ�Ǯ��С�����һ����Ǯ�ޣ�������� 
N
N öӲ�ң�Ӳ�ҵ���ֵ�ֱ�Ϊ 
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
 ��

���죬С������������ 
N
N öӲ��ȥ������ϲ������ߵ�������ѡ�ֻ����������涨��С�����ֻ��ʹ���� 
N
N öӲ���е����� 
3
3 ö��

�Դˣ������С�����㣬��ʹ�ò����� 
3
3 öӲ�ҵ�����£�С���ܹ�֧�������ֲ�ͬ�Ľ���أ�

ע�⣬
0
0 ԪҲ��һ�ֽ�*/
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
