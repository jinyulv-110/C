/*
进制规定了数字在数位上逢几进一。X 进制是一种很神奇的进制, 因为其每一数位的进制并不固定！例如说某种 X 进制数, 
最低数位为二进制, 第二数位为十进制, 第三数位为八进制, 则 X 进制数 321 转换为十进制数为 65 。
现在有两个 X 进制表示的整数 A 和 B, 但是其具体每一数位的进制还不确 定, 只知道 A 和 B 是同一进制规则, 且每一数位最高为 N 进制, 最低为二进制。
请你算出的结果最小可能是多少。
请注意, 你需要保证 A 和 B 在 X 进制下都是合法的, 即每一数位上的数字要小于其进制。
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 10, M = N * 2, INF = 0x3f3f3f3f, Mod = 1e9 + 7;

ll num_A[N], num_B[N], MAX;

int main()
{
    int n, m;
    cin >> MAX >> n;
    for(int i = n; i >= 1; i --) cin >> num_A[i];
    cin >> m;
    for(int i = m; i >= 1; i --) cin >> num_B[i];
    
    ll pre = 1, mx = 0;
    ll res = 0;
    for(int i = 1; i <= max(m, n); i ++) 
    {
       mx = max(2ll, max(num_A[i], num_B[i]) + 1ll);
       res = (res + pre * (num_A[i] - num_B[i] + Mod) % Mod ) % Mod;
       pre = pre * mx % Mod;
    }
       
    cout << res << "\n";
    return 0;
}
