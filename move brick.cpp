/*
这天，小明在搬砖。一共有 n 块砖, 他发现第 i 砖的重量为 wi, 价值为 vi。
他突然想从这些 砖中选一些出来从下到上堆成一座塔, 并且对于塔中的每一块砖来说, 它上面 所有砖的重量和不能超过它自身的价值。
他想知道这样堆成的塔的总价值（即塔中所有砖块的价值和）最大是多少。
*/
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

int n;
pair<int, int> wv[1001];// first 是重量 second是权值
int dp[1001][20001];
int ans;

bool cmp(pair<int, int> x, pair<int, int> y)
{
    return x.first + x.second < y.first + y.second;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> wv[i].first >> wv[i].second;
    sort(wv + 1, wv + n + 1, cmp);//重量大到小 //最优值贪心需要v-m尽量小 反过来v-m增大则说明不行 合理性通过wv[i].second>= j - wv[i].first判断了
    for (int i = 1; i <= n; i++)//当前块放与不放
        for (int j = 1; j <= 20000; j++)//当前的容量
        {
            dp[i][j] = dp[i - 1][j];
            if (wv[i].first <= j && wv[i].second>= j - wv[i].first)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - wv[i].first] + wv[i].second);
            ans = max(ans, dp[i][j]);
        }
    cout << ans;
}
//vi-mj-M>=vj-mi-M;
