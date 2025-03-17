/*

在奥特曼的世界中，也存在着很多选拔性考试，其中在一门名叫奥特曼数理基础的课程中，异或位运算和加法运算是赛文奥特曼每天都要面对的问题。
他发现，这两种运算虽然看起来完全不同，但实际上它们之间存在着一种深度的联系。赛文奥特曼对异或运算和加法运算之间的联系非常好奇，
他总觉得二者之间隐隐有某种联系，所以他想让你求解下列关于异或和加法的问题。

给定长度为N 的序列 {a}，求有多少对 (i,j) 满足 1≤i,j≤n，且 
ai⊕aj=ai+aj，其中 ⊕表示异或操作。
*/
#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;

int n, ans;
int a[1000005];
int d[1 << 20];

signed main() {
    ios::sync_with_stdio(false),cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        ++d[a[i]];
    }
    for (int i = 0; i < 20; ++i) {
        for (int j = 1; j < (1 << 20); ++j) {
            if (j & (1 << i)) {
                d[j] += d[j - (1 << i)];
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        ans += d[(1 << 20) - 1 - a[i]];
    }
    cout << ans;
    return 0;
}
