/*С����һ������Ϊn����������a[1],a[2],��a[n]��
����һ�����������k��С�����ҵ����ڼ��Ϊ1��k����a[p].a[p+2],a[p+4],��,a[p+2k-2],ʹ�����ǵĺ��������1<=p<=n-2k+2��
�������к�k�����ʸ������ĺ�*/
#include <stdio.h>

//�������ڼ��Ϊ1��k�ĸ���������
int findMaxSum(int a[],int n,int k){
	int maxSum=a[0]+a[2]+a[2*(k-1)];
	int p;
	for(p=1;p<=n-2*k+2;p++){
		int sum=0;
	int i;
	for(i=0;i<k;i++){
	sum +=a[p+2*i];
	}
	if (sum>maxSum){
		maxSum=sum;
	}
}
return maxSum;

	
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
	int result=findMaxSum(a,n,k);
	printf("The largest sum is: %d\n",result);
	return 0;
} 
