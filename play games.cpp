/*
һ����Ϸ�����Ӣ�۽��з��࣬һ���� n��ְҵ�� m ����Ӫ��
С��ÿ����һ��Ӣ�ۣ����Ӣ������ĳһ��ְҵ��Ҳ����ĳһ����Ӫ��ÿ��Ӣ������ĳ��ְҵ�ĸ����� 
1/n������ĳ����Ӫ�ĸ����� 1/m ����С�����������ְҵ����Ӫ������������
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
