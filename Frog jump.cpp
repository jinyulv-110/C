/*��һֻ������һ��ֱ������ϵ��ԭ�㴦(0,0)��������Ծ�� N �Σ�ÿ����Ծֻ�������������ĸ����������Ծ��
���ܵ�һ�κ͵ڶ�����Ծ�ľ��붼Ϊ 1��֮��ÿ����Ծ�ľ��룬����ǰ������Ծ����֮�͡�
���ڣ�����ÿ��������Ծ�ķ��������������Ծ�� N �κ�����������ϵ�е�λ�á�
�ĸ������ò�ͬ���ַ���ʾ���������£�

U���ϡ�
R���ҡ�
D���¡�
L����*/
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
