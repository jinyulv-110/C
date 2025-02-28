/*

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;
ll dp[5005][1200];// dp[i][j]表示j状态下 i 位数的个数 j = 0000001011 表示PIN有0、1、3状态 
int main()
{
    int n; cin >> n;
    string num; cin >> num;
    dp[0][0] = 1;
    for(int i = 1;i <= n;i ++) // 遍历位数 
    {
        for(int j = 0;j < 1200;j ++) // 遍历状态
        {
            for(int k = 0;k <= 9;k ++) // 遍历要加入的数字 
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
