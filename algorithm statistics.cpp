/*

�ڰ������������У�Ҳ�����źܶ�ѡ���Կ��ԣ�������һ�����а�������������Ŀγ��У����λ����ͼӷ����������İ�����ÿ�춼Ҫ��Ե����⡣
�����֣�������������Ȼ��������ȫ��ͬ����ʵ��������֮�������һ����ȵ���ϵ�����İ��������������ͼӷ�����֮�����ϵ�ǳ����棬
���ܾ��ö���֮��������ĳ����ϵ��������������������й������ͼӷ������⡣

��������ΪN ������ {a}�����ж��ٶ� (i,j) ���� 1��i,j��n���� 
ai��aj=ai+aj������ ����ʾ��������
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
