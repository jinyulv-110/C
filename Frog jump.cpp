/*有一只青蛙在一个直角坐标系的原点处(0,0)。青蛙跳跃了 N 次，每次跳跃只能沿上下左右四个方向进行跳跃。
青蛙第一次和第二次跳跃的距离都为 1，之后每次跳跃的距离，都是前两次跳跃距离之和。
现在，给出每次青蛙跳跃的方向，请计算青蛙跳跃了 N 次后，青蛙在坐标系中的位置。
四个方向用不同的字符表示，具体如下：

U：上。
R：右。
D：下。
L：左。*/
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
  int arr[11]={0};
  int N,i,x=0,y=0;
  char c;
  arr[1]=1;
  scanf("%d",&N);getchar();
  for(i=2;i<=N;i++)
  {
    arr[i]=arr[i-1]+arr[i-2];
  }
  for(i=1;i<=N;i++)
  {
    scanf("%c ",&c);
    if(c=='U')
    {
      y+=arr[i];
    }
    else if(c=='R')
    {
      x+=arr[i];
    }
    else if(c=='D')
    {
      y-=arr[i];
    }
    else
    {
      x-=arr[i];
    }
  }
  printf("%d %d",x,y);
  return 0;
}
