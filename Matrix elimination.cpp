/*光光正在进行一场矩阵消消乐游戏，有一个 
n×n 的矩阵装满了标有数字的格子，如果格子是 2 的整数次方
就可以将这个格子所在的行和列消掉，规定已被消掉的格子标号为 1，
请你帮她将经历了“消消乐”之后的矩阵输出在控制台。*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int init[1000][100];//创建内部数组（不显示，只参与计算）
  int show[1000][100] = {0};//创建显示数组（不参与计算，只显示）
  int N = 0;
  int i = 0;
  int j = 0;
  int n = 0;
  int a = 0;
  scanf("%d",&N);//录入行数（行数=列数）
  for(i = 0;i < N;i++)
  {
    for(j = 0;j < N;j++)
    {
      scanf("%d",&init[i][j]);//录入数组
      if(show[i][j] != 1)//显示数组不为1则此行此列未参与过消除，此时录入数据
      {
        show[i][j] = init[i][j];
      }
      a = 1;
      n = 0;
      while(a <= init[i][j])//统计计算数组在二进制存储时有几个1
      {
        if((a&init[i][j]) == a)
          n++;
        a<<=1;//a左移移位代表乘2
        if(n > 1)
          break;
      }
      if(n == 1)//只有一个1代表是2的整数次方，此时消除显示数组，使其为1
      {
        for(a = 0;a < N;a++)
        {
          show[i][a] = 1;
        }
        for(a = 0;a < N;a++)
        {
          show[a][j] = 1;
        }
      }
    }
  }
  for(i = 0;i < N;i++)//打印
  {
    for(j = 0;j < N;j++)
    {
      printf("%d ",show[i][j]);
    }
    printf("\n") ;
  }
  return 0;
}
