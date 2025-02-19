/*小智定义一个数 x 的罪恶值为：大于 x 的最小质数和 w 的乘积。
现在给定你一个整数 n，你需要求出 n 的罪恶值。
*/
#include <iostream>
using namespace std;
bool iszhi(long long a){
  for(int i=3;i*i<=a;i=i+2){
    if(a%i==0) return 0;
  }
  return 1;
}
int main()
{
  long long n,w;
  cin>>n>>w;
  n++;
  if(n%2==0) n++;
  if(n==3) cout<<2*w;
  else{
    while(!iszhi(n)) n+=2;
    cout<<(long long)(n*w);
  }
  return 0;
}
