/*����һ�������������ַ����ַ�������ͳ��һ������ַ����г����˶��ٸ� 0 �����ٸ� 1 �����������ٸ� 9 ��
*/
#include <iostream>
using namespace std;
int main()
{
  string n;
  cin>>n;
    for(char i='0';i<='9';i++)
  {
    int t=0;
    for(int j=0;n[j];j++)
    if(n[j]==i)t++;
  cout<<t<<" ";
  }
  return 0;
}
