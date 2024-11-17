/*
小兰在停车场停车
停车场的收费规则是：每15分钟收费2元，不满15分钟，不收费。
小兰总共停车n分钟，请问收费总额是多少？ 
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
