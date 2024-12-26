/*直线相交的判断模板题。
在二维平面直角坐标系中，用坐标 (x P,y P) 描述点 P 的位置。
T 个询问，每个询问给出四个点 
A,B,C,D，判断直线 
AB 和直线 
CD 之间的关系：
若两条直线平行（包括重叠），输出 pingxing。
否则，输出 xiangjiao。*/
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
