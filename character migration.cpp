/*
小蓝最近获得了一个长度为 N 的字符串 S，他对它爱不释手。

小桥为了考验小蓝对字符串的处理能力，决定给他提出一个挑战，她会进行 Q 次操作：

每次操作给定三个整数 
l,r,k，将 S 的第 l 个字符到第 r 个字符都循环右移 k 次。
小桥想让小蓝回答她在操作完成后 S 是多少？小蓝陷入了困境，于是请你帮帮他！
字符右移表示为按字母表进行移动，例如 a 右移 1 次变为 b，b 右移 2 次变为 d。特别地，z 右移 1 次变回为 a。
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> diff(n + 1, 0); // 差分数组
    while (q--) {
        ll l, r, k;
        cin >> l >> r >> k;
        k %= 26;
        diff[l - 1] += k;//下标从0开始的
        diff[r] -= k;
    }
    // 计算前缀和
    for (int i = 1; i < n; ++i) {
        diff[i] += diff[i - 1];
    }
    for (int i = 0; i < n; ++i) {
        int offset = s[i] - 'a';//这点的差值最大为25也就是z减去‘a’的差值
        offset = (offset + diff[i]) % 26;
        s[i] = 'a' + offset;
        ////
    }
    cout << s << endl;
    return 0;
}
