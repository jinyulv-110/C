/*
������ N �����ӣ���֪�����ǵĳ��ȡ�������Ҫ����ѡ�� 3 �������Թ���һ�����˻������εķ�ʽ����

*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  // ���ڴ��������Ĵ���
  int sjx=0;
  int i,j,k;
  int N;//��������Ԫ�ظ���
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
