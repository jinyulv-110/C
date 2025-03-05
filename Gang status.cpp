/*
С������Ϸ�вμ���һ�����ɣ���һ����ͻȻ��֪���Լ��ڰ�������ʲô��λ�����ǰ��ɵĲ�ѯϵͳͻȻ���ˣ�
Ŀǰֻ��֪��ÿ���˵ĸ�����ϵ���������ܰ�����ؽ���ϵ�����ҳ����ĵ�λ��

����һ�������� n ������ð��ɵ�������������С��������� m �������� n ������ÿ���˵ĸ�����ϵ��
ȷ�������Ĺ�ϵ��Ϊһ���������ɵ�λ�Ķ����ǰ����Լ������ж��ٰ��ھ����ģ�
ע�����µ�����Ҳ�����Լ������¡�������µİ�����ͬ����Ž�С����ǰ�档���ܰ���С���ҵ��Լ��İ��ɵ�λ��

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
