/*
���죬С���ڰ�ש��һ���� n ��ש, �����ֵ� i ש������Ϊ wi, ��ֵΪ vi��
��ͻȻ�����Щ ש��ѡһЩ�������µ��϶ѳ�һ����, ���Ҷ������е�ÿһ��ש��˵, ������ ����ש�������Ͳ��ܳ���������ļ�ֵ��
����֪�������ѳɵ������ܼ�ֵ������������ש��ļ�ֵ�ͣ�����Ƕ��١�
*/
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

int n;
pair<int, int> wv[1001];// first ������ second��Ȩֵ
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
    sort(wv + 1, wv + n + 1, cmp);//������С //����ֵ̰����Ҫv-m����С ������v-m������˵������ ������ͨ��wv[i].second>= j - wv[i].first�ж���
    for (int i = 1; i <= n; i++)//��ǰ����벻��
        for (int j = 1; j <= 20000; j++)//��ǰ������
        {
            dp[i][j] = dp[i - 1][j];
            if (wv[i].first <= j && wv[i].second>= j - wv[i].first)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - wv[i].first] + wv[i].second);
            ans = max(ans, dp[i][j]);
        }
    cout << ans;
}
//vi-mj-M>=vj-mi-M;
