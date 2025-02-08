/*
宝玉作为贾府的少爷，每次出行可谓是风光无限，出行时随从数量极多，更是坐着象征尊贵的 "玲珑轿"。
贪玩的宝玉有一个初步的出行计划，这可以用一个长度为 n 的字符串 S 表示：
如果第 i 天宝玉打算出行，则 Si=1;否则 Si=0。

每次出行，宝玉都需要坐上 "玲珑轿"。如果没有干净的 "玲珑轿"，则他不会出行。宝玉具有一定的洁癖,
每次他使用过的 "玲珑轿" 都需要经过 d 天的清洗和整理后才会再次使用。
例如，某辆 "玲珑轿" 在第 
x 天使用了，那么它最快可以在第 (x+d) 天再次使用。

接下来可能会发生 q 个事件，事件包括以下两种：

贾母对宝玉天天出行游玩早已不满，宝玉为了应对贾母，在某些时刻会更改自己的出行计划。贾母不在府上时，
他可能会将某个 Sx=0 变为 Sx=1;贾母在府上时也可能会将某个 Sx=1 变为 Sx=0。
在不断地修改出行计划同时，宝玉会随时询问作为管家的你，如果最初只有 
k 台 "玲珑轿" 可供使用，能否满足当前的出行计划。若能满足则输出 -1，否则输出最早无法成功出行的一天。*/

#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 i128;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
struct Seg{
    #define mx(x) tre[x].mx
    #define tag(x) tre[x].tag
    struct STR{
        ll mx,tag;
    };vector<STR> tre;
    inline void init(int n){
        tre.resize(4*n+10);
    }
    inline void pushup(int u){
        mx(u)=max(mx(u<<1),mx(u<<1|1));
    }
    inline void pushdown(int u){
        if(tag(u)){
            mx(u<<1)+=tag(u);
            mx(u<<1|1)+=tag(u);
            tag(u<<1)+=tag(u);
            tag(u<<1|1)+=tag(u);
            tag(u)=0;
        }
    }
    inline void modify(int u,int tl,int tr,int l,int r,int k){
        if(tl>=l && tr<=r){
            mx(u)+=k;tag(u)+=k;return;
        }pushdown(u);int mid=(tl+tr)>>1;
        if(l<=mid) modify(u<<1,tl,mid,l,r,k);
        if(r>mid) modify(u<<1|1,mid+1,tr,l,r,k);
        pushup(u);
    }
    inline int kth(int u,int tl,int tr,int k){
        if(tl==tr){
            return mx(u)<=k ? -1 : tl;
        }pushdown(u);int mid=(tl+tr)>>1;
        if(k<mx(u<<1)) return kth(u<<1,tl,mid,k);
        return kth(u<<1|1,mid+1,tr,k);
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,d;cin>>n>>d;
    string s;cin>>s;s="0"+s;
    Seg seg;seg.init(n);
    for(int i=1;i<=n;i++){
        if(s[i]=='1'){
            seg.modify(1,1,n,i,min(n,i+d-1),1);
        }
    }int q;cin>>q;
    while(q--){
        int op,x;cin>>op>>x;
        if(op==1){
            int res=s[x]=='1' ? -1 : 1;
            seg.modify(1,1,n,x,min(n,x+d-1),res);
            s[x]^=1;
        }
        if(op==2){
            cout<<seg.kth(1,1,n,x)<<"\n";
        }
    }
    return 0;
}
