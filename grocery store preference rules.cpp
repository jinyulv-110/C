/*
С����Ӫ��һ���ӻ��꣬�ӻ������д� 1 �� n ��ŵĹ� n ����Ʒ��
���Ϊ i ����Ʒ�Ķ���Ϊ ai.��������ֵ�����ڼ䣬С�������������¹�������Żݣ�
��ĳ�˿������˱��Ϊ 
p1,p2,��,pk �� 1��pi��n������Ʒ����ôС�������Żݵļ۸��� 
gcd(ap1,ap2,��,apk)�� ap1,ap2 ,��,a pk �����������

С���������������������ж����ֿ��ܳ��ֵĲ�ͬ���Żݼ۸�
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
