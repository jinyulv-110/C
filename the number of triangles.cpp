/*
乐乐有 N 根棍子，他知道它们的长度。现在他要计算选择 3 根棍子以构建一个非退化三角形的方式数。

*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  // 请在此输入您的代码
  int sjx=0;
  int i,j,k;
  int N;//定义数组元素个数
  scanf("%d",&N);
  int a[N];
  for(i=0;i<N;i++)
  {
    scanf("%d",&a[i]);
  }
  for(i=0;i<N;i++)
  {
      for(j=i+1;j<N-1;j++)
      {
          for(k=j+1;k<N;k++)
          {
              if(a[i]+a[j]>a[k]&&a[i]+a[k]>a[j]&&a[j]+a[k]>a[i])
              {
                  sjx++;
              }
          }
      }
  }
  printf("%d",sjx);
  printf("\n");
  return 0;
}
