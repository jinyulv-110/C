/*
��̫�����μӶ��������ѧ�Ľ���������������̫���ˣ��ڽ����ſ������˳��ӣ���������������𣩡�
����ȴ�ʱ�䣬��Ҷ��ڽ�������ǰ���������ܷ��ҵ���ʶ��ͬѧ��
���Ǵ��ֻ���ϵõ��Լ���������֮�����ˣ�ѧ���ǵ����߻ᱻ�����Լ���ߵ͵��˵�ס����
���ʣ�������̫�����ڵ�ѧ���ǣ���ǰ����ʱ���ܹ��ܹ����������ˣ�
*/
#include <iostream>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <stack>
#include <numeric>
#include <ctime>
#include <string>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <bits/stdc++.h>
#define il inline

using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll N = 2e5 + 5, mod = 998244353, inf = 2e18;

il void solve() {
    int n;
    cin>>n;
    vector<int>a(n+5),stak(n+5);
    int top=0;
    for(int i=1;i<=n;i++)cin>>a[i];
    int ans=0;
    for(int i=1;i<=n;i++){
        while(top&&a[stak[top]]<a[i])top--;
        ans+=i-stak[top]-1;
        //cout<<stak[top]<<" \n"[i==n];
        stak[++top]=i;
    }

    cout<<ans<<'\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t = 1;

    //cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
