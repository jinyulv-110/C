/*
小蓝正在学习一门神奇的语言，这门语言中的单词都是由小写英文字母组成，
有些单词很长，远远超过正常英文单词的长度。小蓝学了很长时间也记不住一些单词，
他准备不再完全记忆这些单词，而是根据单词中哪个字母出现得最多来分辨单词。
现在，请你帮助小蓝，给了一个单词后，帮助他找到出现最多的字母和这 个字母出现的次数。
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  // 请在此输入您的代码
  int count[26]={0},max=0,i;
  char ch;
  while((ch=getchar())!='\n')
    count[ch-'a']++;
  for(i=1;i<26;i++)
    if(count[i]>count[max])
      max=i;
  printf("%c\n%d",max+'a',count[max]);
  return 0;
}
