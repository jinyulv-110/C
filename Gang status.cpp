/*
小明在游戏中参加了一个帮派，这一天他突然想知道自己在帮派中是什么地位，但是帮派的查询系统突然坏了，
目前只能知道每个人的附属关系，请问你能帮帮他重建关系网并找出他的地位吗？

给定一个正整数 n ，代表该帮派的总人数，并且小明的序号是 m ，给出这 n 个人中每个人的附属关系，
确保给出的关系网为一棵树。帮派地位的定义是按照自己手下有多少帮众决定的，
注意手下的手下也算是自己的手下。如果手下的帮众相同则按序号较小的在前面。你能帮助小明找到自己的帮派地位吗？

*/
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 1e5 + 10;
vector<ll>g[N];
ll siz[N];
struct node
{
    ll val = 0;
    ll id = 0;
    bool operator < (const node& it) const
    {
        if (val == it.val)
        {
            return id <= it.id;
        }
        return val >= it.val;
    }
}nd[N];
void dfs(ll u, ll father)
{
    siz[u] = 1;
    for (auto& y : g[u])
    {
        if (y == father)
        {
            continue;
        }
        dfs(y, u);
        siz[u] += siz[y];
    }
}
int main()
{
    ll n = 0, m = 0;
    cin >> n >> m;
    for (ll i = 1; i <= n - 1; i++)
    {
        ll u = 0, v = 0;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, 0);
    for (ll i = 1; i <= n; i++)
    {
        nd[i].val = siz[i];
        nd[i].id = i;
    }
    sort(nd + 1, nd + 1 + n);
    for (ll i = 1; i <= n; i++) 
    {
        if (nd[i].id == m) 
        {
            cout << i << endl;
            break;
        }
    }
    return 0;
}
