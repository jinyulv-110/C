/*
ŵ���ǳ�ϲ�����գ�����ϲ��������Щ���Դ����������Ķ����õ�ͬ������ĶԳ����⡣�����죬����ͼ��ݼ����������صĿ�Ƭ��ÿ�ſ�Ƭ�϶�д��һ��Сд��ĸ��ɵ����롣

ŵ�����룬������ܴ����ſ�Ƭ�������и�ѡ��һ���Ӵ������������Ӵ���β����������ܵõ�һ���ԳƵ��ַ�������ô�����ܽ⿪������⡣

���ڣ�ŵ����Ҫ��İ���������������ſ�Ƭ�ϵ����룬���ܰ����жϳ��Ƿ���������������Ӵ���

*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int n,i,j;
  char arr[1001],brr[1001];
  scanf("%d",&n);
  getchar();
  for(i=0;i<n;i++)
  {
    scanf("%s%s",arr,brr);//���������ַ���
    int hash[26]={0},hbsh[26]={0};
    for(j=0;arr[j];j++)
      hash[arr[j]-'a']++;
    for(j=0;brr[j];j++)
      hbsh[brr[j]-'a']++;
    int flag=1;
    for(j=0;j<26;j++)
    {
      if(hash[j]>=1 && hbsh[j]>=1)
      {
        printf("Yes\n");
        flag=0;
        break;
      }
    }
    if(flag)
      printf("No\n");
  }
  return 0;
} 
