
#include<stdio.h>
#define N 100
 
int search(int *a,int left,int right);
int sum_buf(int *a,int left,int right);
 
int main(void)
{
    int a[N];
    int i;
    int s;
    for(i=0;i<N;i++)
        a[i]=1;
    a[29]=2;//编号为29的物品不合格 假设物品从0开始编号
    s=search(a,0,N-1);
    printf("不合格品的编号为：%d\n",s);
    return 0;
}
 
//计算数组中所有元素之和
int sum_buf(int *a,int left,int right)
{
    int i;
    int sum=0;
    for(i=left;i<=right;i++)
        sum+=a[i];
    return sum;
}
 
//折半查找法 找出数组中最大的元素
int search(int *a,int left,int right)
{
    int mid=(left+right)/2;
    if(left==right-1)
    {
        if(a[left]<a[right])
            return right;
        else
            return left;
    }
    if((right-left)%2==0)//数组中元素为奇数
    {
        if(sum_buf(a,left,mid-1)>sum_buf(a,mid+1,right))
            return search(a,left,mid-1);
        else
            if(sum_buf(a,left,mid-1)<sum_buf(a,mid+1,right))
                return search(a,mid+1,right);
            else
                return mid;
    }
    else//数组中元素为偶数
        if(sum_buf(a,left,mid)>sum_buf(a,mid+1,right))
            return search(a,left,mid);
        else
            return search(a,mid+1,right);
}

