/*
小蓝经营了一家杂货店，杂货店里有从 1 到 n 编号的共 n 个商品，
编号为 i 的商品的定价为 ai.。现在正值节日期间，小蓝决定根据以下规则进行优惠：
设某顾客买走了编号为 
p1,p2,…,pk （ 1≤pi≤n）的商品，那么小蓝给他优惠的价格将是 
gcd(ap1,ap2,…,apk)即 ap1,ap2 ,…,a pk 的最大公因数。

小蓝想请你帮他求出，他共有多少种可能出现的不同的优惠价格。
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int mx=*max_element(a.begin(),a.end());
    vector<bool> ju(mx+1,0);
    int ans=0;
    for(auto cur:a){
        if(!ju[cur]) ans++;
        ju[cur]=1;
    }
    for(int i=1;i<=mx/3;i++){
        if(ju[i]) continue;
        int g=0;
        for(int j=i*2;j<=mx&&g!=i;j+=i){
            if(ju[j]) g=__gcd(g,j);
        }
        if(g==i) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
