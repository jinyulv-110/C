/*
���ƹ涨����������λ�Ϸ꼸��һ��X ������һ�ֺ�����Ľ���, ��Ϊ��ÿһ��λ�Ľ��Ʋ����̶�������˵ĳ�� X ������, 
�����λΪ������, �ڶ���λΪʮ����, ������λΪ�˽���, �� X ������ 321 ת��Ϊʮ������Ϊ 65 ��
���������� X ���Ʊ�ʾ������ A �� B, ���������ÿһ��λ�Ľ��ƻ���ȷ ��, ֻ֪�� A �� B ��ͬһ���ƹ���, ��ÿһ��λ���Ϊ N ����, ���Ϊ�����ơ�
��������Ľ����С�����Ƕ��١�
��ע��, ����Ҫ��֤ A �� B �� X �����¶��ǺϷ���, ��ÿһ��λ�ϵ�����ҪС������ơ�
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
