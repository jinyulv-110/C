/*
С����ͣ����ͣ��
ͣ�������շѹ����ǣ�ÿ15�����շ�2Ԫ������15���ӣ����շѡ�
С���ܹ�ͣ��n���ӣ������շ��ܶ��Ƕ��٣� 
*/
#include <stdio.h> 
int calculateFares(int n){
	return 2*(n/15);
	
}
int main(){
	int n;
	printf("please enter parking duration(min)");
	scanf ("%d",&n);
	int fares=calculateFares(n);
	printf("parking fares:%d yuan\n",fares);
	return 0;
}
