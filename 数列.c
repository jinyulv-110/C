/*小兰有一个长度为n的整数数列a[1],a[2],…a[n]。
对于一个给点的整数k，小兰想找到相邻间隔为1的k个数a[p].a[p+2],a[p+4],…,a[p+2k-2],使得他们的和最大，其中1<=p<=n-2k+2。
给定数列和k，请问给出最大的和*/
#include <stdio.h>

//计算相邻间隔为1的k的个数的最大和
int findMaxSum(int a[],int n,int k){
	int maxSum=a[0]+a[2]+a[2*(k-1)];//初始化最大和
	int p;
	for(p=1;p<=n-2*k+2;p++){
		int sum=0;//每次计算和时，先初始化和为0
	int i;
	for(i=0;i<k;i++){//2
	sum +=a[p+2*i];//计算当前位置的和
	}
	if (sum>maxSum){//比较当前和与最大和
		maxSum=sum;//若当前和更大，更新最大和
	}
}
return maxSum;//返回·最大和

	
}
int main(){
	int n,k;
	printf(" Please enter the series length n:");
	scanf("%d",&n);
	int a[n];
	printf("Please enter the sequence elements");
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		
	}
	printf("Please enter the integer k:");
	scanf("%d",&k);
	int result=findMaxSum(a,n,k);//调用计算函数
	printf("The largest sum is: %d\n",result);//输出结果
	return 0;
} 
