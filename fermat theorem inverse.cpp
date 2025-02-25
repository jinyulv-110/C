/*
给出 n,p，求 
n^-1 mod p。其中， n^-1 mod p 指存在某个整数 
0≤a<p，使得 

na mod p=1，此时称 a为 n 的逆元，即 
a=n^-1。数据保证 p 是质数且 n mod p 不等于0。 
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
