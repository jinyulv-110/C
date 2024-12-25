/*
给定一个正整数和一个额外的数字。你可以将这个数字插入到正整数的任意位置，
包括开头和结尾，目标是使得结果尽可能大。
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
