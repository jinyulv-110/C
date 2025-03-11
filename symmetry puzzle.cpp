/*
诺伊非常喜欢解谜，他最喜欢的是那些可以从两个方向阅读并得到同样结果的对称谜题。星期天，他在图书馆捡到了两张神秘的卡片，每张卡片上都写着一串小写字母组成的密码。

诺伊猜想，如果他能从两张卡片的密码中各选择一段子串，将这两段子串首尾相连，如果能得到一个对称的字符串，那么他就能解开这个谜题。

现在，诺伊需要你的帮助。他会给你两张卡片上的密码，你能帮他判断出是否存在这样的两段子串吗？

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
    scanf("%s%s",arr,brr);//输入两行字符串
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
