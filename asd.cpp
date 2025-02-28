/*

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;
ll dp[5005][1200];// dp[i][j]��ʾj״̬�� i λ���ĸ��� j = 0000001011 ��ʾPIN��0��1��3״̬ 
int main()
{
    int n; cin >> n;
    string num; cin >> num;
    dp[0][0] = 1;
    for(int i = 1;i <= n;i ++) // ����λ�� 
    {
        for(int j = 0;j < 1200;j ++) // ����״̬
        {
            for(int k = 0;k <= 9;k ++) // ����Ҫ��������� 
            {
                dp[i][j | (1 << k)] += dp[i - 1][j] % MOD;
                dp[i][j] %= MOD;
            }    
        } 
    }
    ll sum = 0;
    for(int i = 1;i <= 1024;i ++)
    {
        int flag = true;
        for(int k = 0;k <= 9;k ++)
        {
            if(num[k] == 'o' && ((i >> k)&1) == 0) flag = false;
            if(num[k] == 'x' && ((i >> k)&1) == 1) flag = false;
        }
        if(flag == true) sum += dp[n][i];
        sum %= MOD;
    }
    cout << sum << endl;
    return 0;
}
