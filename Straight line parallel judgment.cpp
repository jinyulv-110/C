/*ֱ���ཻ���ж�ģ���⡣
�ڶ�άƽ��ֱ������ϵ�У������� (x P,y P) ������ P ��λ�á�
T ��ѯ�ʣ�ÿ��ѯ�ʸ����ĸ��� 
A,B,C,D���ж�ֱ�� 
AB ��ֱ�� 
CD ֮��Ĺ�ϵ��
������ֱ��ƽ�У������ص�������� pingxing��
������� xiangjiao��*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int T;
  scanf("%d",&T);


  int a1,a2,b1,b2,c1,c2,d1,d2;
  for(int i=0;i<T;i++){
    scanf("%d %d %d %d %d %d %d %d",&a1,&a2,&b1,&b2,&c1,&c2,&d1,&d2);
    if((a1-b1)*(c2-d2)==(a2-b2)*(c1-d1)){
      printf("pingxing\n");
    }
    else{
      printf("xiangjiao\n");
    }
  }
  return 0;
}
