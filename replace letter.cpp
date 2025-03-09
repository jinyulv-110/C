/*
给定一个仅含小写英文字母的字符串 s, 每次操作选择一个区间 
[li,ri]将 s的该区间中的所有字母 xi全部替换成字母 yi, 问所有操作做完后, 得到的字符串是什么。
*/
#include <iostream>
#include <cstring>
using namespace std;
const int N=1e5+10;
char s[N];
int main()
{
  string s;
  cin>>s;
  int n;
  cin>>n;
  while(n--)
  {
    int l,r;
    char a,b;
    cin>>l>>r>>a>>b;

    int pos=l-2;
     do
     {
       pos=s.find(a,pos+1);
       if(pos!=-1&&pos<r) s[pos]=b;
     }while(pos!=-1&&pos<r);
  }

  cout<<s;
  
  return 0;
}
