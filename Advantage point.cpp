/*
������֪ N �����ڵѿ���ƽ���ϡ�����ÿ���� i������֪���������� xi�� yi
��� xi>xj �� yi >yj��˵�� i ֧��� j��
��������Ҫ�ҳ��Ƿ���һ����֧���������е㣬��ע�⣺û�������������ͬ�� x �� y��
�㱻��Ϊ�� 1 ��ʼ������
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  // ���ڴ��������Ĵ���
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
