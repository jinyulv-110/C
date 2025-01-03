/*
乐乐已知 N 个点在笛卡尔平面上。对于每个点 i，乐乐知道它的坐标 xi和 yi
如果 xi>xj 且 yi >yj们说点 i 支配点 j。
乐乐现在要找出是否有一个点支配其他所有点，请注意：没有两个点具有相同的 x 或 y，
点被认为从 1 开始索引。
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  // 请在此输入您的代码
  int N;
  scanf("%d",&N);
  int a[N],b[N];
  int amax=0,bmax=0,adi=0,bdi=0;
  for(int i=0;i<N;i++)
  {
    scanf("%d %d",&a[i],&b[i]);
    if(a[i]>amax)
    {
    amax=a[i];
    adi=i;
    }
    if(b[i]>bmax)
    {
      bmax=b[i];
      bdi=i;
    }
  }
  if(adi==bdi)printf("%d",adi+1);
  else printf("-1");
  return 0;
}
