/*
���� n,p���� 
n^-1 mod p�����У� n^-1 mod p ָ����ĳ������ 
0��a<p��ʹ�� 

na mod p=1����ʱ�� aΪ n ����Ԫ���� 
a=n^-1�����ݱ�֤ p �������� n mod p ������0�� 
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

int a,p;

int ksm(int a,int b,int mod){
    int ans = 1;
    while(b){
        if(b & 1){
            ans = ans * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}
void solve(){
    cin >> a >> p;
    if(a % p){
        cout << ksm(a,p - 2,p);
    }
}

signed main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t = 1;
//    cin>>t;
    
    while(t--){
        solve();
    }
    return 0;
}
