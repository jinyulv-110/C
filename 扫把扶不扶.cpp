#include <bits/stdc++.h>
using namespace std;

int timeToSeconds(const string& timeStr){
	
	int h,m,s;char c;
	istringstream ss(timeStr);
	ss>> h >>c >>m >>c >>s;
	return h*3600+m*60 +s;
	 
}
string solve(){
	string s1,s2,s3,s4;
	int T,X;
	cin >> s1 >>s2 >>s3>> s4;
	cin >>T >>X;
	int t1= timeToSeconds(s1),t2=timeToSeconds(s2);
	int t3=timeToSeconds(s3),t4 =timeToSeconds(s4);
	bool ok1=true,ok2=true,broom=false;
	
	if(t1>t2) ok1=false;
	if(t3>t4) ok2=false;
	if(t1 + 60 * X <= t2) broom=true;
	if(t1<= t2 &&t2+ 60*T>t4)ok2 =false;
	
	if(broom || (ok1 &&!ok2)) return "You";
	if(!ok1 && !ok2) return "Draw";
	return "Lan";
	 
}
int main()
{
	
	int t;cin >> t;
	while (t--) cout << solve()<<'\n';
	return 0;
}

