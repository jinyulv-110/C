/*
��һ�������� x ���Ա�ʾΪ i2�� i>0����� x Ϊƽ������
������T ��ѯ�ʣ�ÿ��ѯ�ʸ���һ�������� n������ش��ж��ٸ�ƽ����С�ڵ��� n��
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(int argc, char *argv[])
{
  // ���ڴ��������Ĵ���
  int T;
  long long n;
  scanf("%d",&T);
  for(int i=1;i<=T;i++)
  {
    scanf("%lld",&n);
    int sum=(int)sqrt(n);
    printf("%d\n",sum);
  }
return 0;
}
