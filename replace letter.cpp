/*
����һ������СдӢ����ĸ���ַ��� s, ÿ�β���ѡ��һ������ 
[li,ri]�� s�ĸ������е�������ĸ xiȫ���滻����ĸ yi, �����в��������, �õ����ַ�����ʲô��
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
