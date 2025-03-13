/*
W星球的长老交给小明一个任务： 
1,2,3,...16 这 16 个数字分为两组。

要求：这两组数字的和相同，并且，两组数字的平方和也相同，并且，两组数字的立方和也相同。

请你利用计算机的强大搜索能力解决这个问题。 并输出 1 所在的那个分组的所有数字。

这些数字要从小到大排列，两个数字间用一个空格分开。 即类似：1 4 5 8... 这样的答案。
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
