/*
��������������ͬ������������ A �� B������һ������ C������ÿһ��Ԫ�� C[i] �� A[x]+B[y] ����ʽ,
���� 0��x,y<n�����ڣ�����������ҵ� C �е� k С��Ԫ�ء�
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
      scanf("%lld",&a[i]);   //����A
    for(int i=1;i<=n;i++)
       scanf("%lld",&b[i]);   //����B
     int k;                   //Ŀ��ֵ
     scanf("%d",&k); 
     for(int i=1;i<=n;i++)
         for(int j=1;j<=n;j++)
             c[a[i]+b[j]]++;       //ͳ��a[i]+b[j]���ִ���������c
       
       for(ll i=1;i<=2000099;i++)      //Ͱ����
       {
           if(c[i]>=k)      //��>=k,˵����ǰi�ǵ�kС
           {
               printf("%lld\n",i);
               break;
           }
           k-=c[i];         //��<k,��k����Ϊʣ����Ҫ�ҵĸ���
       }
}

int main()
{
    solve();
    return 0; 
}
