/*给定一个仅包含数字字符的字符串，请统计一下这个字符串中出现了多少个 0 、多少个 1 、……、多少个 9 。
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
