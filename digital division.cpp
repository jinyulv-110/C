/*
W����ĳ��Ͻ���С��һ������ 
1,2,3,...16 �� 16 �����ַ�Ϊ���顣

Ҫ�����������ֵĺ���ͬ�����ң��������ֵ�ƽ����Ҳ��ͬ�����ң��������ֵ�������Ҳ��ͬ��

�������ü������ǿ�������������������⡣ ����� 1 ���ڵ��Ǹ�������������֡�

��Щ����Ҫ��С�������У��������ּ���һ���ո�ֿ��� �����ƣ�1 4 5 8... �����Ĵ𰸡�
*/
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string> 
#include<map>
#include<set>
#include<vector>
#define ll long long
#define maxn 100010
using namespace std;
vector<int> ans;
bool vis[17];
int b[17];
int c[17];
int sum1=0;
int sum2=0;
int sum3=0;
void dfs(int pos,int sum_1,int sum_2,int sum_3)
{
    if(sum_1>sum1 || sum_2>sum2 || sum_3>sum3)
    {
        return;
    }
    if(sum_1==sum1 && sum_2==sum2 && sum_3==sum3)
    {
        for(int i=2;i<=16;i++)
        {
            if(vis[i])
            {
                cout<<i<<" ";
            }
        }
        cout<<endl;
        return;
    }
    for(int i=pos;i<=16;i++)
    {
        if(vis[i]==false)
        {
            vis[i]=true;
            dfs(i+1,sum_1+i,sum_2+b[i],sum_3+c[i]);
            vis[i]=false;
        }
    }
}
int main()
{
    for(int i=1;i<=16;i++)
    {
        sum1+=i;
        sum2+=pow(i,2);
        sum3+=pow(i,3);
        b[i]=i*i;
        c[i]=i*i*i;
    }
    sum1/=2;
    sum2/=2;
    sum3/=2;
    vis[1]=true;
    cout<<"1 ";
    dfs(2,1,1,1);
}
