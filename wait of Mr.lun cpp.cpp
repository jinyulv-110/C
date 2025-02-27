/*
伦太郎来参加东京电机大学的讲座，但是来的人太多了，在教室门口排起了长队（队伍从左向右排起）。
在这等待时间，大家都在焦急地向前观望，看能否找到认识的同学，
但是大家只能认得到自己视线所及之处的人（学生们的视线会被不比自己身高低的人挡住）。
请问：包括伦太郎在内的学生们，向前观望时，总共能够看到多少人？
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
