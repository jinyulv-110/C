/*
����һ����������һ����������֡�����Խ�������ֲ��뵽������������λ�ã�
������ͷ�ͽ�β��Ŀ����ʹ�ý�������ܴ�
*/

#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
  int n,d;
  scanf("%d%d",&n,&d);
  char s[200001];
  scanf("%s",s);
  int i=0;
  while(s[i]-'0'>=d) i++;
  for(int j=n;j>i;j--)
    s[j]=s[j-1];
  s[i]=d+'0';
  printf("%s",s);
  return 0;
}
