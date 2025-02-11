#include <iostream>
using namespace std;
int a[10]={6,2,5,5,4,5,6,3,7,6};
int main ()
{
	string x;
	cin >> x;
	int Len=x.size();
	int res=0;
	for(int i=0;i<Len;i++)
	{
		res+=a[x[i]-'0'];
		}
		cout<<res;
		return 0;
}
