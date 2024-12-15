/*������С������ո�ѧϰ�˿���չ������������һ���������������������ˡ�

С������ȥ�̳��齱���ɹ��س鵽�˲��뽱����һ�����У���С��ȴ������Ȥ����������в����˲������ʣ�

����������ڵ��������֣������е���������ʲô�����أ�

��ʽ�أ�

����һ�������� n ��һ������Ϊ n ������ p

���� 
i ���� 1,2,3��n-1�����һ����������ʾ������pi,pi+1�󣬸����е��������� 998244353 ȡģ��*/
#include <bits/stdc++.h>
#define lowbit(x) (x)&(-x)
using namespace std;

typedef long long LL;
const int N = 2e5 + 10;
const LL MOD = 998244353;
int n;
LL tr[N],a[N],fac[N],rev[N];

void add(int x,int c)
{
    for(int i = x;i <= n;i += lowbit(i)) tr[i] += c;
}

LL sum(LL x)
{
    LL res = 0;
    for(int i = x;i;i -= lowbit(i)) res += tr[i];
    return res;
}

int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin >> n;
    
    for(int i = 1;i <= n; i++) cin >> a[i];
    
    fac[0] = 1;
    for(int i = 1;i <= n; i++) fac[i] = fac[i-1] * i % MOD;
    
    LL ans = 0;
    for(int i = n;i >= 1; i--)
    {
        rev[i] = sum(a[i]-1);
        ans = (ans + rev[i] * fac[n-i] % MOD) % MOD;
        add(a[i],1);
    }
     
    for(int i = 1;i + 1 <= n; i++)
    {
        LL res = ans + 1;
        if(a[i] > a[i+1])
        {
            res =  (res + (rev[i+1] - rev[i]) * fac[n - i] % MOD + MOD) % MOD;
            res = (res + (rev[i] - 1 - rev[i+1]) * fac[n - i - 1] % MOD + MOD) % MOD;
        }
        else
        {
            res = (res + (rev[i+1] + 1 - rev[i]) * fac[n - i] % MOD + MOD) % MOD;
            res = (res + (rev[i] - rev[i+1]) * fac[n - i - 1] % MOD + MOD) % MOD;
        }
        cout << res << ' ';
    }
    return 0;
}
  
