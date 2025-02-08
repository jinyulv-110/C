/*
������Ϊ�ָ�����ү��ÿ�γ��п�ν�Ƿ�����ޣ�����ʱ����������࣬���������������� "�����"��
̰��ı�����һ�������ĳ��мƻ����������һ������Ϊ n ���ַ��� S ��ʾ��
����� i �챦�������У��� Si=1;���� Si=0��

ÿ�γ��У�������Ҫ���� "�����"�����û�иɾ��� "�����"������������С��������һ���Ľ��,
ÿ����ʹ�ù��� "�����" ����Ҫ���� d �����ϴ�������Ż��ٴ�ʹ�á�
���磬ĳ�� "�����" �ڵ� 
x ��ʹ���ˣ���ô���������ڵ� (x+d) ���ٴ�ʹ�á�

���������ܻᷢ�� q ���¼����¼������������֣�

��ĸ�Ա�����������������Ѳ���������Ϊ��Ӧ�Լ�ĸ����ĳЩʱ�̻�����Լ��ĳ��мƻ�����ĸ���ڸ���ʱ��
�����ܻὫĳ�� Sx=0 ��Ϊ Sx=1;��ĸ�ڸ���ʱҲ���ܻὫĳ�� Sx=1 ��Ϊ Sx=0��
�ڲ��ϵ��޸ĳ��мƻ�ͬʱ���������ʱѯ����Ϊ�ܼҵ��㣬������ֻ�� 
k ̨ "�����" �ɹ�ʹ�ã��ܷ����㵱ǰ�ĳ��мƻ���������������� -1��������������޷��ɹ����е�һ�졣*/

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
