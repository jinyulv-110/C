/*��֪ n������ x1,x2,... ,xn,�Լ�һ������ 
k��k��n������ 
n ����������ѡ 
k ��������ӣ��ɷֱ�õ�һϵ�еĺ͡����統 
n=4��
k��3��
4 �������ֱ�Ϊ 
3��7��12��19 ʱ���ɵ�ȫ������������ǵĺ�Ϊ�� 
3��7��12=22  3��7��19��29  7��12��19��38  3��12��19��34�� 
���ڣ�Ҫ����������Ϊ�������ж����֡� ����������ֻ��һ�ֵĺ�Ϊ������
3��7��19��29��*/
#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int n,k,sum=0;
int a[101];
int pd(int x){
    for(int i=2;i<sqrt(x);i++){
        if(x%i==0){
            return 1;
        }
    }
    return 0;
}
void dfs(int p,int s,int st){
    if(p==k){
        if(pd(s)!=1){
            sum++;
        }
        return;
    }
    for(int i=st;i<=n;i++){
            p++;
            dfs(p,s+a[i],i+1);
            p--;
    }
    return;
}
int main(int argc, char *argv[])
{
  scanf("%d%d",&n,&k);
  for(int i=1;i<=n;i++){
      scanf("%d",&a[i]);
  }
  dfs(0,0,1);
  printf("%d",sum);
  return 0;
}
